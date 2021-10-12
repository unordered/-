#include <stdio.h>
#include <stdlib.h>


int __cdecl MAX(int x, int y)
{
	int c = 15;
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int main()
{
	// epic 1
	// legendery 2
	// unique 10
	// rare 30
	// uncommon 120
	// common 300

	int count=0;
	while (1)
	{
		int item = rand() % 463;
		printf("아이템 뽑기 --Enter--:");
		getchar();
		if (item < 1)
		{
			printf("[에픽] 아이템!!!!!!!!!\n");
		}
		else if (item < 3)
		{
			printf("[레전더리] 아이템!!!!!!\n");

		}
		else if (item < 13)
		{
			printf("유니크 아이템\n");

		}
		else if (item < 43)
		{
			printf("레어 아이템\n");

		}
		else if (item < 163)
		{
			printf("언커먼 아이템\n");

		}
		else if (item < 463)
		{
			printf("커먼 아이템\n");

		}
		printf("count:%d \n",++count);
	}



	return 0;
}