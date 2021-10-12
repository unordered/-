#include <stdio.h>
#include <stdlib.h>

int main()
{

	char* ary = (char*)malloc(100*5000);

	int time = clock();

	for (int count = 0; count < 10000; count++)
	{
	/*	for (int i = 0; i < 5000; i++)
		{
			for (int j = 0; j < 100; j++)
				*(ary + 5000 * j + i) = 100;
		}*/

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 5000; j++)
				*(ary + 5000 * i + j) = 100;
		}
	}

	printf("time ms: %d\n", clock() - time);
	return 0;
}