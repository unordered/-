#include <stdio.h>
#include "func.h"
#include "homework.h"
int main()
{
	printf("����ī���� ���� 7/15\n");
	while (1)
	{
		printf("���� ��ȣ: ");
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
			printf("�߸��� ��ȣ ����!/n");
			break;
		}


	}
	return 3;
}