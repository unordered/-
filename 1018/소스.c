#include <stdio.h>
#define PROFILE
#include "C:\Users\Empty\source\repos\프로카데미\profiler1009\profiler.h"
#pragma comment(lib,"C:\\Users\\Empty\\source\\repos\\프로카데미\\Debug\\profiler1009.lib")

int main()
{
	// n값을 선업합니다.
	int n;
	// n 값을 입력 받습니다.
	scanf_s("%d", &n);
	
	PRO_BEGIN(L"START");
	// 외부 반복문은 n번만큼 반복하고
	// 내부 반복문은 홀수(2n-1, 2n-3, ..., 1)번 만큼 반복합니다.
	for (int i = n; i >0; i--)
	{
		for (int j = 2*i-1; j > 0; j -=1)
		{
			// *을 출력
			printf("*");
		}
		// 개행
		printf("\n");
	}
	PRO_END(L"START");

	ProfileDataOutText(L"abc");
	return 0;
}