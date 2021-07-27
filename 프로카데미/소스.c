#include <stdio.h>

int add(long a, long b)
{
	long x = a;
	long y = b;
	return (x + y);
}

int main()
{
	long a = 1;
	long b = 2;

	printf("%d\n", add(a, b));


	return 0;
}