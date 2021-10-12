#include "CEnemyObject.h"
#include "CScreenBuffer.h"

extern CScreenBuffer* ScreenBuffer;

CEnemnyObject::CEnemnyObject(int iX, int iY, int iSize)
    :CBaseObject(iSize, iX, iY)
{
    m_ImoveDirection = 0;
    m_iCreateX = 0;
}

CEnemnyObject::~CEnemnyObject()
{
    
}

bool CEnemnyObject::Update(short input)
{

    return false;
}

void CEnemnyObject::Render(void)
{
    ScreenBuffer->Sprite_Draw(_iX, _iY, '@');
}
