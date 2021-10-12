#include "CBulletObject.h"
#include <Windows.h>
#include "CScreenBuffer.h"
#include "CObjectManager.h"

extern CScreenBuffer* ScreenBuffer;

CBulletObject::CBulletObject(int iX, int iY, std::pair<int,int> velocity, CObjcetManager* EnemyList)
    :CBaseObject(1, iX, iY)
{
	x_pos = 0;
	y_pos = 0;
	x_velocity = velocity.first;
	
	life = 0;
	temp = new int[100000];
	y_velocity = velocity.second;
	_EnemyList = EnemyList;
}

bool CBulletObject::Update(short input)
{
	

	if (ready == true)
	{
		
		if (input == VK_LEFT)
		{
			_iX-=1;
		}

		if (input == VK_RIGHT)
		{
			_iX+=1;
		}

		if (input == VK_SPACE)
		{
			y_velocity  = -1;
			ready = false;
		}
	}
	else
	{
		life++;
		if (life == 1)
		{
			return false;
		}

		_iY += y_velocity;
		_iX += x_velocity;

		life = 0;
	}
	Collision();

	// 소멸

	if (_iY >= dfSCREEN_HEIGHT || _iY <= 1 || _iX <=0 || _iX>= dfSCREEN_WIDTH)
	{


		isDelete = true;
	}

    return true;
}



void CBulletObject::Render(void)
{
	ScreenBuffer->Sprite_Draw(_iX, _iY, '*');
}

bool CBulletObject::Collision()
{
	
	for (auto iter = _EnemyList->ObjectList.begin(); iter != _EnemyList->ObjectList.end();)
	{
	
		if ((*iter)->GetObjectType() == 2)// 벽돌(적)충돌
		{
			if ((_iX + x_velocity) == ((*iter)->_iX) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
			
				/*CBaseObject* temp = (*iter);
				iter = _EnemyList->ObjectList.erase(iter);
	
				delete temp;
				
				continue;*/
				(*iter)->isDelete = true;

			}
		}
		else if ((*iter)->GetObjectType() == 0)//플레이어 충돌
		{
			if ((_iX + x_velocity) == ((*iter)->_iX-3) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = -1;
			}
			else if ((_iX + x_velocity) == ((*iter)->_iX-2) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX-1) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				x_velocity = -1;
				y_velocity *= -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX+1) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				x_velocity = -1;
				y_velocity *= -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX+2) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = 1;
			}
			else if ((_iX + x_velocity) == ((*iter)->_iX+3) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = 1;
			}
		}
		else// 벽 충돌
		{
			// y 벽 충돌
			if ((_iY + y_velocity) == 1)
			{
				y_velocity *= -1;
			}
			// x 벽 충돌
			if ((_iX + x_velocity) == 0 || (_iX + x_velocity) == dfSCREEN_WIDTH-2)
			{
				x_velocity *= -1;
			}	


			// 소멸
			if ((*iter)->GetObjectType() == 1)
			{
				if ((*iter)->_iY > dfSCREEN_HEIGHT)
				{

					/*CBaseObject* temp = (*iter);
		
					iter = _EnemyList->ObjectList.erase(iter);
					delete temp;
					return true;*/
					(*iter)->isDelete = true;
				}
			}
		}



		++iter;
	}

	return false;
}

CBulletObject::~CBulletObject()
{
	delete[] temp;
}

bool CPowerBulletObject::Collision()
{
	for (auto iter = _EnemyList->ObjectList.begin(); iter != _EnemyList->ObjectList.end();)
	{

		if ((*iter)->GetObjectType() == 2)// 벽돌(적)충돌
		{
			if ((_iX ) == ((*iter)->_iX) && (_iY ) == ((*iter)->_iY))
			{
				//y_velocity *= -1;
				/*CBaseObject* temp = (*iter);
				iter = _EnemyList->ObjectList.erase(iter);

				delete temp;

				continue;*/
				(*iter)->isDelete = true;
			}
		}
		else if ((*iter)->GetObjectType() == 0)//플레이어 충돌
		{
			if ((_iX + x_velocity) == ((*iter)->_iX - 3) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = -1;
			}
			else if ((_iX + x_velocity) == ((*iter)->_iX - 2) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX - 1) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				x_velocity = -1;
				y_velocity *= -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX + 1) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				x_velocity = -1;
				y_velocity *= -1;

			}
			else if ((_iX + x_velocity) == ((*iter)->_iX + 2) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = 1;
			}
			else if ((_iX + x_velocity) == ((*iter)->_iX + 3) && (_iY + y_velocity) == ((*iter)->_iY))
			{
				y_velocity *= -1;
				x_velocity = 1;
			}
		}
		// 벽 충돌
		{
			// y 벽 충돌
			if ((_iY + y_velocity) == 1)
			{
				y_velocity *= -1;
			}
			// x 벽 충돌
			if ((_iX + x_velocity) == 0 || (_iX + x_velocity) == dfSCREEN_WIDTH - 2)
			{
				x_velocity *= -1;
			}


		}

	


		++iter;
	}



	return false;

}


CPowerBulletObject::CPowerBulletObject(int iX, int iY, std::pair<int,int> vel, CObjcetManager* EnemyList)
	:CBulletObject(iX, iY, vel, EnemyList)
{
	_ObjectType = 3;
	x_pos = 0;
	y_pos = 0;
	x_velocity = 0;
	life = 0;
	y_velocity = 0;
}

void CPowerBulletObject::Render(void)
{

	ScreenBuffer->Sprite_Draw(_iX, _iY, 'P');

}

CPowerBulletObject::~CPowerBulletObject(void)
{
	delete[] temp;
}