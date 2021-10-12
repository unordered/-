#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define PROFILE

#include "profiler.h"



int wmain()
{

	PRO_BEGIN(L"for_500000");
	int a= 0 ;
	for (int i = 0; i < 500000; i++)
	{
		a++;
	}
	PRO_END(L"for_500000");


	PRO_BEGIN(L"for_1500000");
	int b = 0;
	for (int i = 0; i < 1500000; i++)
	{
		b++;
	}
	PRO_END(L"for_1500000");


	PRO_BEGIN(L"for_15000000");
	int c = 0;
	for (int i = 0; i < 15000000; i++)
	{
		c++;
	}
	PRO_END(L"for_15000000");


	PRO_BEGIN(L"sleep1sec");

	Sleep(15888);
	PRO_END(L"sleep1sec");

	ProfileDataOutText(L"abc");
	return 0;
}


