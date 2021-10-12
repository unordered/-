#include "homework.h"
#include <stdio.h>
void shift_binary_print()
{
	int number;
	printf("바이너리로 바꿀 숫자 하나를 입력하세요(0~255):");
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
		printf("비트 위치(-1종료):");
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
				printf("%d 번째 Bit: %d\n",i+1, 1);
			else
				printf("%d 번째 Bit: %d\n",i+1, 0);
		}

	}
}

void bit_bytesplit()
{
	/*
	위치 (1~4) : 1
값 [0~255] : 255
1 번째 바이트 값 : 255
2 번째 바이트 값 : 0
3 번째 바이트 값 : 0
4 번째 바이트 값 : 0

전체 4바이트 값 : 0x000000ff
	*/
	int flagbit = 0;
	int pos = 0;
	int value = 0;
	while (1)
	{
		printf("위치 (1~4): ");
		scanf_s("%d", &pos);
		
		printf("값 [0~255]: ");
		scanf_s("%d", &value);

		// 해당 자리 비트 0으로 비워주기
		flagbit = flagbit & ~(255 << (pos - 1) * 8);
		// 해당 자리 비트 or로 채우기
		flagbit = flagbit | (value << ((pos - 1) * 8));

		for (int i = 0; i < 4; i++)
		{
			printf("%u 번째 바이트 값: %d\n", i + 1, (unsigned char)(flagbit >> (i) * 8) & 255);
		}

		printf("전체 4바이트 값 %08x\n", flagbit);
		

	}
}
