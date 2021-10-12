//IDE<-- 개발 환경
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // atoi 함수를 사용하기 위해 include

#define PHTONE_NUMBER_LENGTH 50

int main(void) // void는 인자로 아무것도 넣지 않는 다는 것을 명시적으로 표현한 것
{
	int age=0; // <--char 타입이고 이름이 a인 변수 1개를 선언한다. 
	
	// 변수는 선언 + 초기화가 필요. 
	char full_phone_number[PHTONE_NUMBER_LENGTH] = { 0 }; // 번호가 들어갈 총 공간 길이가 20인 char타입의 배열을 선언하고 동시에 내부 원소들을 0으로 초기화.
	//  010-5874-3273 
	int pre_zero_phone_count[3] = { 0 }; // 번호 안에 앞에서 0이 아닌 숫자가 나올 때 까지 0의 갯수, 길이가 3인 int타입의 배열을 선언하고 동시에 내부 원소들을 0으로 초기화.
	// 1  0  0
	char part_phone_number[3][10] = { 0 };
	// 10   5874   3273

	/*
		for문으로 part_phone_number 2차원 배열을 초기화. 
	*/
	

	// 콘솔에 [ input Phone No : ]를 출력해 줌.
	printf("input Phone No : "); 
	// 
	// 0001234-100123-0902
	scanf("%s", full_phone_number);// 문자, 숫자 등을 입력받을 때 사용하는 scanf
	
	// full_phton_number<-- [0001234-100123-0902]
	// pre_zero_phone_count<-- 0, 0, 0
	// part_phone_number< -- 0, 0, 0


	// 문자열 분리 과정
	// 입력 문자열 예시: 012-0456-0089
	int total_count = 0;
	int inner_index = 0;
	int pre_zero = 0;

	// part_phone_number에 -를 빼고 각각 원소를 넣고, 문자 앞에 0의 갯수를 세는 작업을 진행
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
	// part_phone_number< -- 1234, 100123, 902 (문자열) 


	
	// 번호가 정수형으로 저장
	int part_phone_number_int[3];
	//  10 5874 3273 <--- 정수형
	//  1   0   0 
	
	for (int i = 0; i < 3; i++)
	{

		part_phone_number_int[i] = atoi(part_phone_number[i]);// part_phone_number에 있는 문자열 번호를 모두 숫자로 전환해서 저장
	
	}
	// full_phton_number<-- [0001234-100123-0902]
	// pre_zero_phone_count<-- 3, 0, 1
	// part_phone_number< -- 1234, 100123, 902(문자열)
	// int part_phone_number_int--> 1234,100123,902(정수)

	printf("My Phone No. : ");
	// 출력부분
	// part_phone_number_int 3242, 322911, 4983 <---
	// pre_zero_phone_count  6,  3,  1 <--- 
	// 0000003242-000322911-04983
	// part_phone_number_int와 pre_zero_phone_count를 이용해서 앞에 0과, 번호를 정수형으로 출력
	for (int i = 0; i < 3; i++)
	{
		// pre_zero_phone_count을 활용해서 0을 찍음  
		for (int j = 0; j < pre_zero_phone_count[i]; j++)
		{
			printf("0");
		}
		// 0이였으면 그냥 나오고
		if(part_phone_number_int[i]!=0)
			printf("%d", part_phone_number_int[i]);

		// '-'를 출력하는데, 만약 마지막이면 출력하지 않는다. 
		if (i != 2)
			printf("-");
	}

	printf("\n");
	printf("Press <RETURN> to close this window...\n");
	return 0;
}