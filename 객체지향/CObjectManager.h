#pragma once

#include "CbaseObject.h"
#include <list>

// 오브젝트들을 관리할 클래스 전역 또는 싱클돈
class CObjcetManager
{
public:

	// 생성해줄 요소
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