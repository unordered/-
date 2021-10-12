#pragma once
#include "CbaseObject.h"

class CPlayerObject : public CBaseObject
{
public:
	CPlayerObject(int iX, int iY, int iSize);
	virtual ~CPlayerObject();

	virtual bool Update(short playerInput);
	virtual void Render(void);

protected:
	int m_ImoveDirection;
	int m_iCreateX;
};