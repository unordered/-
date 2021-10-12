#pragma once
#include "CObjectManager.h"

class CSceneGame
{
CObjcetManager* ObjectManager = new CObjcetManager();

public:	
	CSceneGame();
	void Update(short);
	void PaintWall();
};