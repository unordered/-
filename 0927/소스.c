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
		printf("������ �̱� --Enter--:");
		getchar();
		if (item < 1)
		{
			printf("[����] ������!!!!!!!!!\n");
		}
		else if (item < 3)
		{
			printf("[��������] ������!!!!!!\n");

		}
		else if (item < 13)
		{
			printf("����ũ ������\n");

		}
		else if (item < 43)
		{
			printf("���� ������\n");

		}
		else if (item < 163)
		{
			printf("��Ŀ�� ������\n");

		}
		else if (item < 463)
		{
			printf("Ŀ�� ������\n");

		}
		printf("count:%d \n",++count);
	}



	return 0;
}