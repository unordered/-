#include <stdio.h>
#include <Windows.h>
#include <timeapi.h>

#pragma comment(lib,"winmm.lib")

int main()
{
	int start = (int)timeGetTime();

	int hit[5] = { 0 };
	for (;;)
	{
		system("cls");

		int e = (int)timeGetTime()- start;
		printf("%d ms\n", e);
		printf("3000 ms: %d\n", e);
		
		if (_kbhit())
		{
			printf("hit\n", e, hit);
			_getch();

		}

	}

	return 0;
}