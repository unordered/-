#pragma once
#include "CbaseObject.h"
#include "CObjectManager.h"

class CItemObject : public CBaseObject
{
public:
	int x_pos = 0;
	int y_pos = 0;
	int x_velocity = 0;
	int y_velocity = 0;
	int life = 0;

	// type 0: 벽을 관통하는 총알
	// type 1: 현시점 모든 총알의 갯수가 2배
	int item_type =0;
	

	// 메모리 누수 확인용변수
	void* temp;
	bool playerCollision;
	bool ready = true;
	CObjcetManager* _EnemyList;

	CItemObject(int iX, int iY, int iSize, CObjcetManager* EnemyList);
	virtual bool Update(short);
	virtual void Render(void);
	bool Collision();
	~CItemObject();
};