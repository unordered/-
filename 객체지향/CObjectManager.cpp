#include "CObjectManager.h"
#include "CScreenBuffer.h"
#include "CPlayerObjcet.h"
#include "CBulletObject.h"
#include "CEnemyObject.h"
#include "CItem.h"
#include <Windows.h>
extern CScreenBuffer* ScreenBuffer;

CObjcetManager::CObjcetManager()
{
	
}

void CObjcetManager::CreateObbject(int objectType, int _iX, int _iY)
{
	if (objectType == 2) //몬스터
	{
		this->ObjectList.push_back(new CEnemnyObject(_iX,_iY,2));
	}
	else if (objectType == 1) // 총알
	{
		this->ObjectList.push_back(new CBulletObject(_iX, _iY, std::make_pair(0,0), this));
		bulletCount++;
	}
	else if (objectType == 0) // 캐릭터
	{
		this->ObjectList.push_back(new CPlayerObject(_iX, _iY, 0));
	}
	else if (objectType == 3) // 강화총알
	{
		this->ObjectList.push_back(new CPowerBulletObject(_iX, _iY, std::make_pair(0,0),this));
	}
	else if (objectType == 4) // 아이템
	{
		this->ObjectList.push_back(new CItemObject(_iX, _iY, 4, this));
	}
}

void CObjcetManager::DestroyObject()
{
	
}

void CObjcetManager::Update(short playerInput)
{
	if (playerInput == VK_UP)
	{
		CreateObbject(1, this->ObjectList.front()->_iX, this->ObjectList.front()->_iY-1);
	}
	if (playerInput == VK_DOWN)
	{
		CreateObbject(3, this->ObjectList.front()->_iX, this->ObjectList.front()->_iY - 1);
	}


	//if (playerInput == VK_SPACE)
	//{
	//	CreateObbject(1, this->ObjectList.front()->_iX, this->ObjectList.front()->_iY - 1);
	//}

	
	for (auto element : this->ObjectList)
	{
		element->Update(playerInput);
	}



	// 삭제 요소들 다 삭제해주기
	for (auto iter = this->ObjectList.begin(); iter != this->ObjectList.end(); )
	{
		if ((*iter)->isDelete)
		{
			// 몬스터일 경우 아이템 생성
			if ((*iter)->GetObjectType() == 2)
			{
				CItemObject* tempItem = new CItemObject((*iter)->_iX,  (*iter)->_iY, 4,  this);
				tempItem->item_type = 1;
				CreateItemList->push_back(tempItem);
			}
			else if ((*iter)->GetObjectType() == 4 && bulletCount <128 ) // 아이템 && 플레이어 충돌일경우, 총알 2배 생성
			{
				
				CItemObject* tempItem = (CItemObject *)(*iter);
				if (tempItem->playerCollision == 1)
				{
					// 현재 모든 총알 아이템 생성
					for (auto element : this->ObjectList)
					{
						if (element->GetObjectType() == 1)
						{
							CBulletObject* tempbullet = (CBulletObject*)element;
							if (tempbullet->ready == true)
							{
								continue;
							}
							tempbullet->ready = false;
							CBulletObject* bullet = nullptr;
						

							if (tempbullet->_iX == 1)
							{
								
								bullet = new CBulletObject(tempbullet->_iX + 1,
									tempbullet->_iY, std::make_pair(tempbullet->x_velocity * -1, tempbullet->y_velocity * -1), this);
							}
							else 
							{
								bullet = new CBulletObject(tempbullet->_iX - 1,
									tempbullet->_iY, std::make_pair(tempbullet->x_velocity * -1, tempbullet->y_velocity * -1), this);
							}

							bullet->ready = false;
						
							CreateItemList->push_back((CBaseObject*)bullet);
							bulletCount++;
							break;
						}
					}
				}
			}
			if ((*iter)->GetObjectType() == 1)
			{
				bulletCount--;
			}
			CBaseObject* temp = (*iter);
			iter=this->ObjectList.erase(iter);
			delete temp;

		}
		else
		{
			++iter;
		}
	}


	// 생성 요소들 다 생성해주기
	for (auto iter = CreateItemList->begin(); iter != CreateItemList->end(); )
	{
		this->ObjectList.push_back(*iter);
		iter++;
	}

	CreateItemList->clear();
}

void CObjcetManager::Render()
{
	ScreenBuffer->Buffer_Clear();
	for (auto element : this->ObjectList)
	{
		element->Render();
	}

	if(this->ObjectList.size() !=0)
	bulletCounterRender();
}

void CObjcetManager::bulletCounterRender()
{
	int hnumber= (bulletCount/100);
	ScreenBuffer->Sprite_Draw(14, 0,(char)(hnumber+48)  );
	int tnumber = (bulletCount / 10);
	ScreenBuffer->Sprite_Draw(15, 0, (char)(tnumber + 48));
	int ohnumber = (bulletCount % 10);
	ScreenBuffer->Sprite_Draw(16, 0, (char)(ohnumber + 48));
}
