#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;

	int* ptr = (int*)malloc(sizeof(int) * 1000);
	*(ptr + 15) = 15;

	return 0;
}