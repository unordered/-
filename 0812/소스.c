#include <stdio.h>

void f()
{
	int c = 0;
}

int main(void)
{
	int a = 16;
	int b = 17 ;
	int c = 18;

	printf("a:");
	scanf_s("%d", &a);


	printf("b:");
	scanf_s("%d", &b);


	printf("c:");
	scanf_s("%d", &c);

	f();
	printf("아무키나 누르면 연산 시작");
	getchar();

	int d = 7 * a + 8 * b;

	printf("%d\n", d);

	return 0;
}