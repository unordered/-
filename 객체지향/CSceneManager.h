#pragma once
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneTitle.h"

class CSceneManager
{
private:
	CsceneOver* sceneOver;
	SceneTitle* sceneTitle;
	CSceneGame* sceneGame;

public:
	CSceneManager();
	CSceneManager* GetInstance();
	void run(short);
};