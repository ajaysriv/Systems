/*
 * Ajay Srivastava (as1877) & Srihari Chekuri (svc31)
 * main.c for sorted-list.c
 */

#include <stdio.h>
#include <string.h>
#include "sorted-list.h"

/* 
 * Test Comparator Functions
 * <0 if the First Object is Smaller 	(if Obj 1 < Obj 2)
 * =0 if the Two Objects are equal		(if Obj 1 == Obj 2)
 * >0 if the Second Object is Smaller 	(if Obj 1 > Obj 2)
 */
int compareInts (void * p1, void * p2) {
    int first = *(int *) p1;
    int second = *(int *) p2;
    if (first == second) {
        return 0;
    } else if (first < second) {
        return -1;
    }
    return 1;
}

void destroy(void *data)
{
	int first = *(int *) data;
	printf("%d\n", first);
//	printf(" I DESTROYED THE DATA\n");
	return;
}

int main(int argc, char **argv)
{
    printf("This is the main file\n");

    // Test Case 1 (Integers)
//	printf("\e[1;32mTest Case 1: \n\e[0m");
    SortedListPtr test1 = SLCreate(compareInts, destroy);
	int intArray[10] = {9, 32, 48, 61, 1, 31, 4, 11, 12, 12};

	int i;

	for(i=0; i<10; i++)
	{
		if(SLInsert(test1, &intArray[i]) == 0)
			printf("\e[1;31mThere was an error\n\e[0m");
	}
	SLRemove(test1, &intArray[1]);
	SLDestroy(test1);
	SLGetItem(NULL);
	return 0;
}