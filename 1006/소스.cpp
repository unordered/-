#include <stdio.h>
#include <intrin.h>
#include <windows.h>
#pragma comment(lib, "Winmm.lib")

#pragma intrinsic(__rdtsc)

int main()
{
    //// cpu Ŭ���� ����ϴ� ����(����:clock)
    unsigned __int64 cpu_clock = 0;

    //// timeGetTime���� ���κ�����ġ�� �ð����(����:ms)
    //// startTime�� �ý��� ���� �� ��� �ð��� ms�� ����.
    //int startTime = timeGetTime();

    //// rdtsc�� ���� Ŭ���� cpu_clock�� ������ �����
    //cpu_clock = __rdtsc();

    //// 1�ʸ� ��ٸ�.
    //while ((timeGetTime()- startTime)!=1000)
    //{
    //     
    //}
    //// 1�ʰ� cpu Ŭ���� �󸶳� �ٲ������ cpu_clock�� ����
    //cpu_clock = __rdtsc() - cpu_clock;

    //// ����� ���� CPU �۵� �ð��� ����ϰ� ����
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

      Sleep(1000); // �׽�Ʈ�� delay :1 ��


    QueryPerformanceCounter(&end);

    printf("timefrequency %ld\n", timefeq.LowPart);
    tinterval = (float)(end.QuadPart - start.QuadPart) / timefeq.QuadPart;

    printf("tinterval: %f\n", tinterval);


    return 0;
}

