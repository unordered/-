//IDE<-- ���� ȯ��
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // atoi �Լ��� ����ϱ� ���� include

#define PHTONE_NUMBER_LENGTH 50

int main(void) // void�� ���ڷ� �ƹ��͵� ���� �ʴ� �ٴ� ���� ��������� ǥ���� ��
{
	int age=0; // <--char Ÿ���̰� �̸��� a�� ���� 1���� �����Ѵ�. 
	
	// ������ ���� + �ʱ�ȭ�� �ʿ�. 
	char full_phone_number[PHTONE_NUMBER_LENGTH] = { 0 }; // ��ȣ�� �� �� ���� ���̰� 20�� charŸ���� �迭�� �����ϰ� ���ÿ� ���� ���ҵ��� 0���� �ʱ�ȭ.
	//  010-5874-3273 
	int pre_zero_phone_count[3] = { 0 }; // ��ȣ �ȿ� �տ��� 0�� �ƴ� ���ڰ� ���� �� ���� 0�� ����, ���̰� 3�� intŸ���� �迭�� �����ϰ� ���ÿ� ���� ���ҵ��� 0���� �ʱ�ȭ.
	// 1  0  0
	char part_phone_number[3][10] = { 0 };
	// 10   5874   3273

	/*
		for������ part_phone_number 2���� �迭�� �ʱ�ȭ. 
	*/
	

	// �ֿܼ� [ input Phone No : ]�� ����� ��.
	printf("input Phone No : "); 
	// 
	// 0001234-100123-0902
	scanf("%s", full_phone_number);// ����, ���� ���� �Է¹��� �� ����ϴ� scanf
	
	// full_phton_number<-- [0001234-100123-0902]
	// pre_zero_phone_count<-- 0, 0, 0
	// part_phone_number< -- 0, 0, 0


	// ���ڿ� �и� ����
	// �Է� ���ڿ� ����: 012-0456-0089
	int total_count = 0;
	int inner_index = 0;
	int pre_zero = 0;

	// part_phone_number�� -�� ���� ���� ���Ҹ� �ְ�, ���� �տ� 0�� ������ ���� �۾��� ����
	for (int index = 0; index < PHTONE_NUMBER_LENGTH; index++)
	{
		if (full_phone_number[index] == 0)
			break;

		if (full_phone_number[index] == '-')
		{
			total_count++;
			inner_index = 0;
			pre_zero = 0;
			continue;
		}

		if (full_phone_number[index] == '0' && pre_zero ==0)
		{
			pre_zero_phone_count[total_count]++;
		
		}
		else
		{
			pre_zero = 1;
			part_phone_number[total_count][inner_index] = full_phone_number[index];
			inner_index++;
		}
	}
	// full_phton_number<-- [0001234-100123-0902]
	// pre_zero_phone_count<-- 3, 0, 1
	// part_phone_number< -- 1234, 100123, 902 (���ڿ�) 


	
	// ��ȣ�� ���������� ����
	int part_phone_number_int[3];
	//  10 5874 3273 <--- ������
	//  1   0   0 
	
	for (int i = 0; i < 3; i++)
	{

		part_phone_number_int[i] = atoi(part_phone_number[i]);// part_phone_number�� �ִ� ���ڿ� ��ȣ�� ��� ���ڷ� ��ȯ�ؼ� ����
	
	}
	// full_phton_number<-- [0001234-100123-0902]
	// pre_zero_phone_count<-- 3, 0, 1
	// part_phone_number< -- 1234, 100123, 902(���ڿ�)
	// int part_phone_number_int--> 1234,100123,902(����)

	printf("My Phone No. : ");
	// ��ºκ�
	// part_phone_number_int 3242, 322911, 4983 <---
	// pre_zero_phone_count  6,  3,  1 <--- 
	// 0000003242-000322911-04983
	// part_phone_number_int�� pre_zero_phone_count�� �̿��ؼ� �տ� 0��, ��ȣ�� ���������� ���
	for (int i = 0; i < 3; i++)
	{
		// pre_zero_phone_count�� Ȱ���ؼ� 0�� ����  
		for (int j = 0; j < pre_zero_phone_count[i]; j++)
		{
			printf("0");
		}
		// 0�̿����� �׳� ������
		if(part_phone_number_int[i]!=0)
			printf("%d", part_phone_number_int[i]);

		// '-'�� ����ϴµ�, ���� �������̸� ������� �ʴ´�. 
		if (i != 2)
			printf("-");
	}

	printf("\n");
	printf("Press <RETURN> to close this window...\n");
	return 0;
}