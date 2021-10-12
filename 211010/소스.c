#include <stdio.h>
#pragma comment(lib,"C:\\Users\\Empty\\source\\repos\\프로카데미\\Debug\\profiler1009.lib")
#define PROFILE
#include "C:\Users\Empty\source\repos\프로카데미\profiler1009\profiler.h"
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