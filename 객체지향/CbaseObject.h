#pragma once

class CBaseObject
{
public:
	CBaseObject(int ObjectType, int X, int Y);
	virtual ~CBaseObject();

	virtual bool Update(short) = 0;
	virtual void Render(void) = 0;

	int GetObjectType();

public:
	int		_iX;
	int		_iY;
	int		_ObjectType;

	bool isDelete = false;
};


