#include <stdio.h>
#define PROFILE
#include "C:\Users\Empty\source\repos\����ī����\profiler1009\profiler.h"
#pragma comment(lib,"C:\\Users\\Empty\\source\\repos\\����ī����\\Debug\\profiler1009.lib")

int main()
{
	// n���� �����մϴ�.
	int n;
	// n ���� �Է� �޽��ϴ�.
	scanf_s("%d", &n);
	
	PRO_BEGIN(L"START");
	// �ܺ� �ݺ����� n����ŭ �ݺ��ϰ�
	// ���� �ݺ����� Ȧ��(2n-1, 2n-3, ..., 1)�� ��ŭ �ݺ��մϴ�.
	for (int i = n; i >0; i--)
	{
		for (int j = 2*i-1; j > 0; j -=1)
		{
			// *�� ���
			printf("*");
		}
		// ����
		printf("\n");
	}
	PRO_END(L"START");

	ProfileDataOutText(L"abc");
	return 0;
}