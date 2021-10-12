#include <stdio.h>
#include <intrin.h>
#include <windows.h>
#pragma comment(lib, "Winmm.lib")

#pragma intrinsic(__rdtsc)

int main()
{
    //// cpu 클록을 기록하는 변수(단위:clock)
    unsigned __int64 cpu_clock = 0;

    //// timeGetTime으로 메인보드장치로 시간기록(단위:ms)
    //// startTime에 시스템 시작 후 경과 시간을 ms로 받음.
    //int startTime = timeGetTime();

    //// rdtsc로 현재 클록을 cpu_clock에 변수에 기록함
    //cpu_clock = __rdtsc();

    //// 1초를 기다림.
    //while ((timeGetTime()- startTime)!=1000)
    //{
    //     
    //}
    //// 1초간 cpu 클록이 얼마나 바뀌었는지 cpu_clock에 저장
    //cpu_clock = __rdtsc() - cpu_clock;

    //// 결과는 실제 CPU 작동 시간과 비슷하게 나옴
    //printf("%lf GHz\n", ((cpu_clock/1000.0)/1000.0)/1000.0);
    //int i = 0;
    //cpu_clock = __rdtsc();
  

    //

    //cpu_clock = __rdtsc() - cpu_clock;
    //printf("clock: %lld\n", cpu_clock);












    LARGE_INTEGER timefeq, start, end;
    float tinterval;

    QueryPerformanceFrequency(&timefeq);
    QueryPerformanceCounter(&start);

      Sleep(1000); // 테스트로 delay :1 초


    QueryPerformanceCounter(&end);

    printf("timefrequency %ld\n", timefeq.LowPart);
    tinterval = (float)(end.QuadPart - start.QuadPart) / timefeq.QuadPart;

    printf("tinterval: %f\n", tinterval);


    return 0;
}

