#include "CSceneTitle.h"
#include "CScreenBuffer.h"

extern CScreenBuffer* ScreenBuffer;


SceneTitle::SceneTitle()
{
}

bool SceneTitle::Update(short playerInput)
{
	
	PaintTitle();

	if (playerInput != 0x23)
	{
		// °ÔÀÓ¾À 2·Î..
		return true;
	}
	return false;
}

void SceneTitle::PaintTitle()
{


	ScreenBuffer->Sprite_Draw(24, dfSCREEN_HEIGHT / 2-2, 'T');
	ScreenBuffer->Sprite_Draw(25, dfSCREEN_HEIGHT / 2 - 2, 'i');
	ScreenBuffer->Sprite_Draw(26, dfSCREEN_HEIGHT / 2 - 2, 't');
	ScreenBuffer->Sprite_Draw(27, dfSCREEN_HEIGHT / 2 - 2, 'l');
	ScreenBuffer->Sprite_Draw(28, dfSCREEN_HEIGHT / 2 - 2, 'e');

	ScreenBuffer->Sprite_Draw(20, dfSCREEN_HEIGHT /2, 'P');
	ScreenBuffer->Sprite_Draw(21, dfSCREEN_HEIGHT / 2, 'r');
	ScreenBuffer->Sprite_Draw(22, dfSCREEN_HEIGHT / 2, 'e');
	ScreenBuffer->Sprite_Draw(23, dfSCREEN_HEIGHT / 2, 's');
	ScreenBuffer->Sprite_Draw(24, dfSCREEN_HEIGHT / 2, 's');
	ScreenBuffer->Sprite_Draw(25, dfSCREEN_HEIGHT / 2, ' ');
	ScreenBuffer->Sprite_Draw(26, dfSCREEN_HEIGHT / 2, 'E');
	ScreenBuffer->Sprite_Draw(27, dfSCREEN_HEIGHT / 2, 'n');
	ScreenBuffer->Sprite_Draw(28, dfSCREEN_HEIGHT / 2, 't');
	ScreenBuffer->Sprite_Draw(29, dfSCREEN_HEIGHT / 2, 'e');
	ScreenBuffer->Sprite_Draw(30, dfSCREEN_HEIGHT / 2, 'r');
	ScreenBuffer->Sprite_Draw(31, dfSCREEN_HEIGHT / 2, ' ');
	ScreenBuffer->Sprite_Draw(32, dfSCREEN_HEIGHT / 2, 'K');
	ScreenBuffer->Sprite_Draw(33, dfSCREEN_HEIGHT / 2, 'e');
	ScreenBuffer->Sprite_Draw(34, dfSCREEN_HEIGHT / 2, 'y');



}
