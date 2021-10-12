#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <strsafe.h>
#include <time.h>


struct Test
{
	int x;
	int y;
	int z;
	char name[322];
};

int main()
{
	struct Test t;
	t.x = 10;
	t.y = 20;
	t.z = 30;

	struct Test b;
	clock_t time =  clock();
	printf("%ld\n", time);
	b = t;
	
	time = clock();
	printf("%ld\n", time);

	DWORD startTickCount = GetTickCount();
	DWORD currentTickCount;


	while (1)
	{
		time = clock();
		printf("%ld\n", time);
		currentTickCount = GetTickCount();
		printf("%d\n", currentTickCount);

	}

	//while (1)
	//{
	//	//strcpy_s(name, 10, name2);
	//	StringCchCopy(name, 10, name2);
	//	printf("정상종료\n");
	//}
	return 0;
}