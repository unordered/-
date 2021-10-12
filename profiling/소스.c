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
	LARGE_INTEGER start_time; //시작 시간
	__int64 sum_time; // 총 함
	int call_count; // 호출 횟수
	__int64 avg; // 평균 시간
	__int64 max; // 최대 시간
	__int64 min; // 최소 시간
	char profile_name[100]; // 이름
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
	// 이름 있는지 확인 
	for (int i = 0; i < 100; i++)
	{
		// 있으면 해당 프로파일 구조체를 대상으로
		if (strcmp(name, profile_info_list[i].profile_name) == 0, profile_info_list[i].used == 1)
		{
			// 이미 존재하던 것
			// 시간 측정 코드
			QueryPerformanceCounter(&profile_info_list[i].start_time);
			
			return;
		}
	}
	// 없으면 새로운 할당
	for (int i = 0; i < 100; i++)
	{
		// 있으면 해당 프로파일 구조체를 대상으로
		if (profile_info_list[i].used == 0)
		{
			// 초기화
			init_profile(&profile_info_list[i]);
			// 이름세팅

			strcpy_s(profile_info_list[i].profile_name, _countof(profile_info_list[i].profile_name), name);
			profile_info_list[i].used = 1;
			return;
		}
	}


	

}

void end_profile(const char* name)
{
	// 이름 있는지 확인 
	for (int i = 0; i < 100; i++)
	{
		// 있으면 해당 프로파일 구조체를 대상으로
		if (strcmp(name, profile_info_list[i].profile_name) == 0, profile_info_list[i].used == 1)
		{
			// 이미 존재하던 것
			LARGE_INTEGER last_time;
			// 시간 측정 코드
			QueryPerformanceCounter(&last_time);
			profile_info_list[i].sum_time += last_time.QuadPart - profile_info_list[i].start_time.QuadPart;
			__int64 temp_time = last_time.QuadPart - profile_info_list[i].start_time.QuadPart;
			
			profile_info_list[i].call_count++;
			// 최대 최소값 등록
			if (temp_time > profile_info_list[i].max)
			{
				profile_info_list[i].max = temp_time;
			}
			if (temp_time < profile_info_list[i].min)
			{
				profile_info_list[i].min = temp_time;
			}

			// 시작시간 다시 0으로 초기화
			profile_info_list[i].start_time.QuadPart = 0;

			return;
		}
	}

	// 없으면 바로 종료
	{
		// 종료코드
		int* p = 0;
		*p = 9;
	}


}



LARGE_INTEGER Frequency;

// 초기화 함수
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
	printf("---------------------------프로 파일링 결과----------------------------\n");
	for (int i = 0; i < 100; i++)
	{
		if(profile_info_list[i].used==1)
			printf("번호:%d, 이름: %s, AVG: %lld, MAX: %lld, MIN: %lld\n",i,profile_info_list[i].profile_name, profile_info_list[i].avg, profile_info_list[i].max/ Frequency.QuadPart, profile_info_list[i].min/ Frequency.QuadPart);
	}
	return;
}