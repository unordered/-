#include <stdio.h>
#include <memory.h>
#include <Windows.h>
#include <list>
#include <time.h>
#include "Console.h"
#include "CScreenBuffer.h"
#include "CObjectManager.h"
#include "CInput.h"
#include "CSceneManager.h"

// TODO
// ½Ì±ÛÅæÀ¸·Î COjbectManager ¸¸µé±â
//CObjcetManager* ObjectManager = new CObjcetManager();
CScreenBuffer* ScreenBuffer = new CScreenBuffer();
CSceneManager* SceneManager = new CSceneManager();
CInput* Input = new CInput();

int main()
{

	while (true)
	{

		SHORT pInput = Input->PlayerInput();

		SceneManager->GetInstance()->run(pInput);

		// ObjectManager->Update(pInput);
		//ObjectManager->Render();

		ScreenBuffer->Flip();
		Sleep(100);

	}


	return 0;
}