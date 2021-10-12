#include "CbaseObject.h"

CBaseObject::CBaseObject(int ObjectType, int X, int Y)
{
    _iX = X;
    _iY = Y;
    _ObjectType = ObjectType;
}

CBaseObject::~CBaseObject()
{
}

bool CBaseObject::Update(short playerInput)
{
    return false;
}

void CBaseObject::Render(void)
{
}

int CBaseObject::GetObjectType()
{

    return _ObjectType;
}
