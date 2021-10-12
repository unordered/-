#include "CItem.h"
#include "CScreenBuffer.h"
#include "CbaseObject.h"
#include "CBulletObject.h"

extern CScreenBuffer* ScreenBuffer;

CItemObject::CItemObject(int iX, int iY, int iSize, CObjcetManager* EnemyList)
    :CBaseObject(iSize, iX, iY)
{
	x_pos = iX;
	y_pos = iY;
	x_velocity = 0;
	life = 0;
	temp = new int[1000000];
	y_velocity = +1;
	_EnemyList = EnemyList;
	_ObjectType = 4;
}

bool CItemObject::Update(short)
{
    _iY += 1;
	Collision();
	//if (Collision())
	//{
	//	if (item_type == 0) // 관통 총알
	//	{
	//		CBaseObject* player = _EnemyList->ObjectList.front();
	//		_EnemyList->CreateObbject(3, player->_iX, player->_iY);
	//	}
	//	else if (item_type == 1) // 현재 총알 모두 2배
	//	{
	//		auto endIter = _EnemyList->ObjectList.end();
	//		endIter--;

	//		for (auto iter = _EnemyList->ObjectList.begin(); iter != endIter; iter++)
	//		{
	//			if ((*iter)->GetObjectType() == 1)
	//			{
	//				//// TODO CREATE OBJECT
	//				//CBulletObject* pr = (CBulletObject*)(*iter);
	//				//_EnemyList->ObjectList.push_back(new CBulletObject(pr->x_pos,pr->y_pos,
	//				//	std::make_pair(pr->x_velocity*-1,pr->y_velocity), _EnemyList ));
	//				playerCollision = 1;
	//			}
	//			else
	//			{
	//			}

	//		}

	//	}
	//}
	return true;
}

void CItemObject::Render(void)
{
	if (item_type == 0)
	{
		ScreenBuffer->Sprite_Draw(_iX, _iY, 'p');
	}
	else if (item_type == 1)
	{
		ScreenBuffer->Sprite_Draw(_iX, _iY, '2');
	}
}

bool CItemObject::Collision()
{
	for (auto iter = _EnemyList->ObjectList.begin(); iter != _EnemyList->ObjectList.end(); iter++)
	{

		if ((*iter)->GetObjectType() == 0)// 플레이어와 충돌 확인
		{
			if ((_iX) == ((*iter)->_iX - 3) && (_iY) == ((*iter)->_iY)) // 플레이어 충돌 처리
			{
				isDelete = true;
				playerCollision = 1;
				return true;
			}
			if ((_iX) == ((*iter)->_iX-2) && (_iY) == ((*iter)->_iY)) // 플레이어 충돌 처리
			{
				isDelete = true;
				playerCollision = 1;
				return true;
			}
			if ((_iX) == ((*iter)->_iX-1) && (_iY) == ((*iter)->_iY)) // 플레이어 충돌 처리
			{
				isDelete = true;
				playerCollision = 1;
				return true;
			}
			if ((_iX) == ((*iter)->_iX) && (_iY) == ((*iter)->_iY)) // 플레이어 충돌 처리
			{
				isDelete = true;
				playerCollision = 1;
				return true;
			}
			if ((_iX) == ((*iter)->_iX+1) && (_iY) == ((*iter)->_iY)) // 플레이어 충돌 처리
			{
				isDelete = true;
				playerCollision = 1;
				return true;
			}
			if ((_iX) == ((*iter)->_iX+2) && (_iY) == ((*iter)->_iY)) // 플레이어 충돌 처리
			{
				isDelete = true;
				playerCollision = 1;
				return true;
			}
			if ((_iX) == ((*iter)->_iX+3) && (_iY) == ((*iter)->_iY)) // 플레이어 충돌 처리
			{
				isDelete = true;
				playerCollision = 1;
				return true;
			}
		}
	
	}

	// 소멸

	if (_iY > dfSCREEN_HEIGHT)
	{
		isDelete = true;
		playerCollision = 0;

		return true;
	}
	
    return false;
}

CItemObject::~CItemObject()
{
	delete[] temp;
}
