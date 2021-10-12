#include "CSceneGame.h"
#include "CObjectManager.h"
#include "CScreenBuffer.h"

extern CScreenBuffer* ScreenBuffer;

CSceneGame::CSceneGame()
{
	// 캐릭터 생성
	ObjectManager->CreateObbject(0, dfSCREEN_WIDTH / 2, dfSCREEN_HEIGHT - 3);

	// 벽돌생성
	for (int i = 2; i < dfSCREEN_HEIGHT-13; i++)
	{
		for (int j = 1; j < dfSCREEN_WIDTH; j++)
		{
			ObjectManager->CreateObbject(2,j,i);
		}
	}

	// 총알생성
	ObjectManager->CreateObbject(1, dfSCREEN_WIDTH / 2, dfSCREEN_HEIGHT - 4);
	
}

void CSceneGame::Update(short playerInput)
{
	
	ObjectManager->Update(playerInput); 

	ObjectManager->Render();
	PaintWall();
}

void CSceneGame::PaintWall()
{
	ScreenBuffer->Sprite_Draw(0, 0, 'b');
	ScreenBuffer->Sprite_Draw(1, 0, 'u');
	ScreenBuffer->Sprite_Draw(2, 0, 'l');
	ScreenBuffer->Sprite_Draw(3, 0, 'l');
	ScreenBuffer->Sprite_Draw(4, 0, 'e');
	ScreenBuffer->Sprite_Draw(5, 0, 't');
	ScreenBuffer->Sprite_Draw(6, 0, ' ');
	ScreenBuffer->Sprite_Draw(7, 0, 'C');
	ScreenBuffer->Sprite_Draw(8, 0, 'o');
	ScreenBuffer->Sprite_Draw(9, 0, 'u');
	ScreenBuffer->Sprite_Draw(10, 0, 'n');
	ScreenBuffer->Sprite_Draw(11, 0, 't');
	ScreenBuffer->Sprite_Draw(12, 0, ':');


	{
		for (int i = 0; i < dfSCREEN_WIDTH; i++)
		{
			ScreenBuffer->Sprite_Draw(i,1, '$');

		}

		for (int i = 1; i < dfSCREEN_HEIGHT; i++)
		{
			ScreenBuffer->Sprite_Draw(0, i, '$');

		}

		for (int i = 1; i <= dfSCREEN_HEIGHT; i++)
		{
			ScreenBuffer->Sprite_Draw(dfSCREEN_WIDTH - 2, i, '$');

		}

		for (int i = 0; i < dfSCREEN_WIDTH; i++)
		{
			ScreenBuffer->Sprite_Draw(i, dfSCREEN_HEIGHT - 1, '$');

		}

	}
}

