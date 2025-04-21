#include "timer.h"

clock_t startTimer()
{
    clock_t start = clock();
    return start;
}

clock_t stopTimer()
{
    clock_t end = clock();
    return end;
}

double timerResult(int start, int end)
{
    double timeTaken = ((double)end - start) / CLOCKS_PER_SEC;
    return timeTaken;
}