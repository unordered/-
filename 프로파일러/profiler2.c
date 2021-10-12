#include "profiler.h"
#include <string.h>


int vaild_index();
int search_index(WCHAR* tag);

typedef struct targetProfile
{
	int vaild; // 0 ��ȿ��, 1��ȿ���� ����.

	LARGE_INTEGER	lStartTime;			// �������� ���� ���� �ð�.

	long long tick;
	LARGE_INTEGER sumTime;
	long long max;
	long long min;
	WCHAR tag_name[200];
}targetProfile;

targetProfile profile_list[50];
int profile_count;

LARGE_INTEGER timefeq;

void ProfileBegin(WCHAR* szName)
{
	QueryPerformanceFrequency(&timefeq);
	int index = search_index(szName);
	if (index != -1)
	{
		return;
	}
	else
	{
		
		index = vaild_index();
		wcscpy_s(profile_list[index].tag_name,200, szName);
		profile_list[index].vaild = 1;
		profile_list[index].tick = 0;
		profile_list[index].max= INT_MIN;
		profile_list[index].min = INT_MAX;
		QueryPerformanceCounter(&profile_list[index].lStartTime);
	}
}

void ProfileEnd(WCHAR* szName)
{
	for (int index = 0; index < 50; index++)
	{
		if (wcscmp(profile_list[index].tag_name, szName) == 0)
		{
			// �ð� ����
			LARGE_INTEGER curTime;
			QueryPerformanceCounter(&curTime); 
			profile_list[index].tick++;
			profile_list[index].sumTime.QuadPart += curTime.QuadPart-profile_list[index].lStartTime.QuadPart;
		

			break;
		}
	}
}

void ProfileDataOutText(WCHAR* szFileName)
{
	for (int index = 0; index < 50; index++)
	{
		if (profile_list[index].vaild == 1)
		{
			wprintf(L"tag:%s, time: %lld ms\n", profile_list[index].tag_name, (profile_list[index].sumTime.QuadPart/10/1000) / profile_list->tick);
		}
	}

}

void ProfileReset(void)
{


}

// �±׷� �ε��� ã��
int search_index(WCHAR* tag)
{
	for (int i = 0; i < 50; i++)
	{
		if (wcscmp(profile_list[i].tag_name, tag) == 0)
		{
			return i;
		}
	}

	return -1;
}


int vaild_index()
{
	for (int i = 0; i < 50; i++)
	{
		if (profile_list[i].vaild == 0)
		{
			return i;
		}
	}

	return -1;
}