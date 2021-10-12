#pragma once
#include "CbaseObject.h"
#include "CObjectManager.h"
 
class CBulletObject : public CBaseObject
{
public:
	int x_pos=0;
	int y_pos=0;
	int x_velocity=0;
	int y_velocity=0;
	int life=0;
	
	// 메모리 누수 확인용변수
	void* temp;

	bool ready=true;
	CObjcetManager* _EnemyList;

	CBulletObject(int iX, int iY, std::pair<int, int> _vel, CObjcetManager* EnemyList);
	virtual bool Update(short);
	virtual void Render(void);
	virtual bool Collision();
	~CBulletObject();
};

class CPowerBulletObject : public CBulletObject
{
public:
	CPowerBulletObject(int iX, int iY, std::pair<int, int>  _vel, CObjcetManager* EnemyList);
	~CPowerBulletObject();
	virtual void Render(void);
	virtual bool Collision();
};