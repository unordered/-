#include <stdio.h>

int main()
{
	int i = 2;
	int j = 1;
	while (j<=9)
	{
		i = 2;
		while (i <= 5)
		{
			printf("%d * %d = %2d    ", i, j, i * j);
			i++;
		}
		printf("\n");
		i++;
		j++;

	}

	printf("\n");

	j = 1;
	while (j <= 9)
	{
		i = 6;
		while (i <= 9)
		{
			printf("%d * %d = %2d    ", i, j, i * j);
			i++;
		}
		printf("\n");
		i++;
		j++;

	}

	return 0;
}