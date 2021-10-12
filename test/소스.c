#include <stdio.h>

int main(void)
{

	int input;
	int c = 0x77777777;
	while (1)
	{
		printf("비밀번호를 입력하세요: ");
		scanf_s("%d", &input);
		
		if (input == c)
		{
			return;
		}
	}



	return;
}