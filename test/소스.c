#include <stdio.h>

int main(void)
{

	int input;
	int c = 0x77777777;
	while (1)
	{
		printf("��й�ȣ�� �Է��ϼ���: ");
		scanf_s("%d", &input);
		
		if (input == c)
		{
			return;
		}
	}



	return;
}