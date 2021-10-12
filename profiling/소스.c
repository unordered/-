#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <windows.h>

#define USE_PROFILEING

#ifdef USE_PROFILEING
	#define BEGIN_PROFILING(X) start_profile(X)
	#define END_PROFILING(X) end_profile(X)
#else
	#define BEGIN_PROFILING(X)
	#define END_PROFILING(X) 
#endif

void start_profile(const char* name);
void end_profile(const char* name);
void init_profile(struct profile_info* in_info);
void print_profile(void);

struct profile_info
{
	int used;
	LARGE_INTEGER start_time; //���� �ð�
	__int64 sum_time; // �� ��
	int call_count; // ȣ�� Ƚ��
	__int64 avg; // ��� �ð�
	__int64 max; // �ִ� �ð�
	__int64 min; // �ּ� �ð�
	char profile_name[100]; // �̸�
};

struct profile_info profile_info_list[100];

int main(void)
{
	
	int sum = 0;
	for (int i = 1; i < 54552; i++)
	{
		BEGIN_PROFILING("STUPID_ADDITION");

		sum = i % i;

		END_PROFILING("STUPID_ADDITION");
	}
	


	print_profile();
	return 0;
}


void start_profile(const char* name)
{
	// �̸� �ִ��� Ȯ�� 
	for (int i = 0; i < 100; i++)
	{
		// ������ �ش� �������� ����ü�� �������
		if (strcmp(name, profile_info_list[i].profile_name) == 0, profile_info_list[i].used == 1)
		{
			// �̹� �����ϴ� ��
			// �ð� ���� �ڵ�
			QueryPerformanceCounter(&profile_info_list[i].start_time);
			
			return;
		}
	}
	// ������ ���ο� �Ҵ�
	for (int i = 0; i < 100; i++)
	{
		// ������ �ش� �������� ����ü�� �������
		if (profile_info_list[i].used == 0)
		{
			// �ʱ�ȭ
			init_profile(&profile_info_list[i]);
			// �̸�����

			strcpy_s(profile_info_list[i].profile_name, _countof(profile_info_list[i].profile_name), name);
			profile_info_list[i].used = 1;
			return;
		}
	}


	

}

void end_profile(const char* name)
{
	// �̸� �ִ��� Ȯ�� 
	for (int i = 0; i < 100; i++)
	{
		// ������ �ش� �������� ����ü�� �������
		if (strcmp(name, profile_info_list[i].profile_name) == 0, profile_info_list[i].used == 1)
		{
			// �̹� �����ϴ� ��
			LARGE_INTEGER last_time;
			// �ð� ���� �ڵ�
			QueryPerformanceCounter(&last_time);
			profile_info_list[i].sum_time += last_time.QuadPart - profile_info_list[i].start_time.QuadPart;
			__int64 temp_time = last_time.QuadPart - profile_info_list[i].start_time.QuadPart;
			
			profile_info_list[i].call_count++;
			// �ִ� �ּҰ� ���
			if (temp_time > profile_info_list[i].max)
			{
				profile_info_list[i].max = temp_time;
			}
			if (temp_time < profile_info_list[i].min)
			{
				profile_info_list[i].min = temp_time;
			}

			// ���۽ð� �ٽ� 0���� �ʱ�ȭ
			profile_info_list[i].start_time.QuadPart = 0;

			return;
		}
	}

	// ������ �ٷ� ����
	{
		// �����ڵ�
		int* p = 0;
		*p = 9;
	}


}



LARGE_INTEGER Frequency;

// �ʱ�ȭ �Լ�
void init_profile(struct profile_info* in_info)
{
	QueryPerformanceFrequency(&Frequency);

	in_info->used = 0;
	in_info->avg = 0;
	in_info->call_count = 0;
	in_info->max = 0;
	in_info->min = LLONG_MAX;
	memset(in_info->profile_name, 0, sizeof(in_info->profile_name));
	in_info->start_time.HighPart = 0;
	in_info->start_time.LowPart = 0;
	in_info->sum_time = 0;
	
}

void print_profile(void)
{
	printf("-----------------------------------------------------------------------\n");
	printf("---------------------------���� ���ϸ� ���----------------------------\n");
	for (int i = 0; i < 100; i++)
	{
		if(profile_info_list[i].used==1)
			printf("��ȣ:%d, �̸�: %s, AVG: %lld, MAX: %lld, MIN: %lld\n",i,profile_info_list[i].profile_name, profile_info_list[i].avg, profile_info_list[i].max/ Frequency.QuadPart, profile_info_list[i].min/ Frequency.QuadPart);
	}
	return;
}