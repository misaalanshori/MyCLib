// Measures the time to look up a value from an index 1000 times. 
// In Windows compiled with TCC clock() returns miliseconds since start, 
// this might be different depending on your system.

#include <stdio.h>
#include <time.h>
#define listLength 380000

#define DLL_IMPL
#include "../MyCLib.h"

int main() {
    dlinkedlist *testList = dllCreate();
    clock_t t;
    for (int i = 0; i < listLength; i++)
    {
        dllAppend(testList, i*i);
    }
    clock_t t1 = clock();
    for (int i = 0; i < (*testList).length; i += 100)
    { 
        t = clock();
        for (int j = 0; j < 1000; j++)
        {
            dllGet(testList, i);
        }
        t = clock() - t;
        printf("\nIndex: %d, Time (ms): %d", i, t);
        // printf("\n%d,%d", i, t);

    }
    printf("\n");
    t1 = clock() - t1;
    printf("\n\nTotal Time (ms):%d\n", t1);
}