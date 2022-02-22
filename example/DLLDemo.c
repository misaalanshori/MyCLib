#include <stdio.h>

#define DLL_IMPL
#include "../MyCLib.h"

int main() {
    struct dlinkedlist *testList = dllCreate();
    printf("Starting length: %d\n", (*testList).length);
    printf("First value: %d\n", dllGet(testList, 0));
    printf("Set new value: %d\n", dllSet(testList, 0, 12));
    printf("Get the new value: %d\n", dllGet(testList, 0));
    printf("Append a new value: %d\n", dllAppend(testList, 69));
    printf("Get the appended value: %d\n", dllGet(testList, 1));
    printf("Get Current Length %d\n", (*testList).length);
    printf("Append a new value: %d\n", dllAppend(testList, 420));
    printf("Append a new value: %d\n", dllAppend(testList, 450));
    printf("Append a new value: %d\n", dllAppend(testList, 45540));
    printf("Append a new value: %d\n", dllAppend(testList, 43636));
    printf("Get the appended value: %d\n", dllGet(testList, 2));
    printf("Get the first value: %d\n", dllGet(testList, 0));
    printf("Get the second value: %d\n", dllGet(testList, 1));
    printf("Get the third value: %d\n", dllGet(testList, 2));
    printf("Pop the third value: %d\n", dllPop(testList, 2));
    printf("Get a non existent value: %d\n", dllGet(testList, 100));
    printf("Get Final Length %d\n", (*testList).length);
    printf("Looping Over values: \n");
    for (int i = 0; i < (*testList).length; i++)
    {
        printf("%d ", dllGet(testList, i));
    }
    printf("\n");
    printf("Pop the third value again: %d\n", dllPop(testList, 0));
    printf("Get Final Length %d\n", (*testList).length);
    printf("Looping Over values: \n");
    for (int i = 0; i < (*testList).length; i++)
    {
        printf("%d ", dllGet(testList, i));
    }
    printf("\n");
}