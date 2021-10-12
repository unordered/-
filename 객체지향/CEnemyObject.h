#pragma once

#include "CbaseObject.h"

class CEnemnyObject : public CBaseObject
{
public:
	CEnemnyObject(int iX, int iY, int iSize);
	virtual ~CEnemnyObject();

	virtual bool Update(short);
	virtual void Render(void);

protected:
	int m_ImoveDirection;
	int m_iCreateX;

};