#include "CPlayerObjcet.h"
#include "CScreenBuffer.h"
#include <Windows.h>


extern CScreenBuffer* ScreenBuffer;

CPlayerObject::CPlayerObject(int iX, int iY, int iSize)
    :CBaseObject(iSize, iX, iY)
{
    m_ImoveDirection = 0;
    m_iCreateX = 0;
}

CPlayerObject::~CPlayerObject()
{
}

bool CPlayerObject::Update(short playerInput)
{
    if (playerInput == VK_UP)
    {
        //_iY--;
    }
    if (playerInput == VK_DOWN)
    {
        //_iY++;
    }

    if (playerInput == VK_LEFT)
    {
        if ((_iX) != 4)
        {
            _iX -= 1;
        }
        else
        {

        }
    }

    if (playerInput == VK_RIGHT)
    {
        if ((_iX) != dfSCREEN_WIDTH - 6)
        {
            _iX += 1;
        }
        else
        {

        }

    }
    return true;
}

void CPlayerObject::Render(void)
{
    // 스크린 버퍼에 스프라이트 출력

    ScreenBuffer->Sprite_Draw(_iX-3, _iY, '-');
    ScreenBuffer->Sprite_Draw(_iX-2, _iY, '-');
    ScreenBuffer->Sprite_Draw(_iX-1, _iY, '-');
    ScreenBuffer->Sprite_Draw(_iX-0, _iY, '-');
    ScreenBuffer->Sprite_Draw(_iX+1, _iY, '-');
    ScreenBuffer->Sprite_Draw(_iX+2, _iY, '-');
    ScreenBuffer->Sprite_Draw(_iX+3, _iY, '-');
}
