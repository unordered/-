#pragma once
#include "CObjectManager.h"

class SceneTitle
{
	CObjcetManager* ObjectManager = new CObjcetManager();

public:
	SceneTitle();
	bool Update(short);
	void PaintTitle();
};