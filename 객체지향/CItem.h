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

	// type 0: ���� �����ϴ� �Ѿ�
	// type 1: ������ ��� �Ѿ��� ������ 2��
	int item_type =0;
	

	// �޸� ���� Ȯ�ο뺯��
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