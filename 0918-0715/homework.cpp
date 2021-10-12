#include "homework.h"
#include <stdio.h>
void shift_binary_print()
{
	int number;
	printf("���̳ʸ��� �ٲ� ���� �ϳ��� �Է��ϼ���(0~255):");
	scanf_s("%d", &number);


	// 0000 ----------   0101 1101
	// 000000000000000   1000 0000
	for (int i = 0; i < 8; i++)
	{
		if ((number & 128) == 128)
		{
			printf("%d", 1);
		}
		else
		{
			printf("%d", 0);
		}

		number *= 2;
	}
	return;
}

void shift_bitflag_input()
{
	int bitflag = 0;
	int flag = 0;
	int bitNumber = 0;
	int base = 1;
	while (1)
	{
		printf("��Ʈ ��ġ(-1����):");
		scanf_s("%d", &bitNumber);

		printf("OFF/ON [0,1] :");
		scanf_s("%d", &flag);

		if (flag == 0)
		{
			bitflag = bitflag & ~(1 << (bitNumber-1));
		}
		else	
		{ 
			bitflag = bitflag | (1 << (bitNumber - 1));
		}


		
		for (int i = 0; i < 16; i++)
		{
			if ((bitflag & (1 << i)) != 0)
				printf("%d ��° Bit: %d\n",i+1, 1);
			else
				printf("%d ��° Bit: %d\n",i+1, 0);
		}

	}
}

void bit_bytesplit()
{
	/*
	��ġ (1~4) : 1
�� [0~255] : 255
1 ��° ����Ʈ �� : 255
2 ��° ����Ʈ �� : 0
3 ��° ����Ʈ �� : 0
4 ��° ����Ʈ �� : 0

��ü 4����Ʈ �� : 0x000000ff
	*/
	int flagbit = 0;
	int pos = 0;
	int value = 0;
	while (1)
	{
		printf("��ġ (1~4): ");
		scanf_s("%d", &pos);
		
		printf("�� [0~255]: ");
		scanf_s("%d", &value);

		// �ش� �ڸ� ��Ʈ 0���� ����ֱ�
		flagbit = flagbit & ~(255 << (pos - 1) * 8);
		// �ش� �ڸ� ��Ʈ or�� ä���
		flagbit = flagbit | (value << ((pos - 1) * 8));

		for (int i = 0; i < 4; i++)
		{
			printf("%u ��° ����Ʈ ��: %d\n", i + 1, (unsigned char)(flagbit >> (i) * 8) & 255);
		}

		printf("��ü 4����Ʈ �� %08x\n", flagbit);
		

	}
}
