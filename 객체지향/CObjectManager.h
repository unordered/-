#pragma once

#include "CbaseObject.h"
#include <list>

// ������Ʈ���� ������ Ŭ���� ���� �Ǵ� ��Ŭ��
class CObjcetManager
{
public:

	// �������� ���
	std::list<CBaseObject*>* CreateItemList = new std::list<CBaseObject*>();
	CObjcetManager();
	std::list<CBaseObject*> ObjectList;
	int bulletCount = 0;
	void CreateObbject(int objectType, int _iX, int _iY);
	void DestroyObject();
	void Update(short playerInput);
	void Render();

	void bulletCounterRender();

};