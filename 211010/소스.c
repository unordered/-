#include <stdio.h>
#pragma comment(lib,"C:\\Users\\Empty\\source\\repos\\����ī����\\Debug\\profiler1009.lib")
#define PROFILE
#include "C:\Users\Empty\source\repos\����ī����\profiler1009\profiler.h"
#include "mathAge.h"
int age = 15;


int main()
{	
	PRO_BEGIN(L"aaa");
	printf("age:% d\n", age);
	printAge();
	age++;
	printf("age:% d\n", age);
	printAge();
	PRO_END(L"aaa");

	ProfileDataOutText(L"aaaaa");
	return 0;
}