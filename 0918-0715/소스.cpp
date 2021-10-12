#include <stdio.h>
#include "func.h"
#include "homework.h"
int main()
{
	printf("프로카데미 과제 7/15\n");
	while (1)
	{
		printf("과제 번호: ");
		int homework = 0;
		scanf_s("%d", &homework);

		switch (homework)
		{
		case 1:
			shift_binary_print();
			break;
		case 2:
			shift_bitflag_input();
			break;
		case 3:
			bit_bytesplit();
			break;
		default:
			printf("잘못된 번호 선택!/n");
			break;
		}


	}
	return 3;
}