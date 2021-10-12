#pragma once

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#ifdef PROFILE
#define PRO_BEGIN(TagName)	ProfileBegin(TagName)
#define PRO_END(TagName)	ProfileEnd(TagName)
#endif


#ifndef PROFILE
#define PRO_BEGIN(TagName)
#define PRO_END(TagName)
#endif

/////////////////////////////////////////////////////////////////////////////
// �ϳ��� �Լ� Profiling ����, �� �Լ�.
//
// Parameters: (char *)Profiling�̸�.
// Return: ����.
/////////////////////////////////////////////////////////////////////////////
void ProfileBegin(WCHAR* szName);
void ProfileEnd(WCHAR* szName);

/////////////////////////////////////////////////////////////////////////////
// Profiling �� ����Ÿ�� Text ���Ϸ� ����Ѵ�.
//
// Parameters: (char *)��µ� ���� �̸�.
// Return: ����.
/////////////////////////////////////////////////////////////////////////////
void ProfileDataOutText(WCHAR* szFileName);

/////////////////////////////////////////////////////////////////////////////
// �������ϸ� �� �����͸� ��� �ʱ�ȭ �Ѵ�.
//
// Parameters: ����.
// Return: ����.
/////////////////////////////////////////////////////////////////////////////
void ProfileReset(void);