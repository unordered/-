#pragma once
#include "Console.h"
// ȭ�� ����� ������ Ŭ���� �̱���

class CScreenBuffer
{
private:
	char szScreenBuffer[dfSCREEN_HEIGHT][dfSCREEN_WIDTH];
public:
	CScreenBuffer();
	char ScreenBuffer[24][81];
	void Sprite_Draw(int iX, int iY, char chSprite);
	void Flip();
	void Buffer_Clear(void);
};