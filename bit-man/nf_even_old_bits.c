
/*
2595. Number of Even and Odd Bits
You are given a positive integer n.

Let even denote the number of even indices in the binary representation of n (0-indexed) with value 1.

Let odd denote the number of odd indices in the binary representation of n (0-indexed) with value 1.

Return an integer array answer where answer = [even, odd].

Example 1:

Input: n = 17
Output: [2,0]
Explanation: The binary representation of 17 is 10001. 
It contains 1 on the 0th and 4th indices. 
There are 2 even and 0 odd indices.
Example 2:

Input: n = 2
Output: [0,1]
Explanation: The binary representation of 2 is 10.
It contains 1 on the 1st index. 
There are 0 even and 1 odd indices.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>			// File Control Definitions.
#include <termios.h>		// POSIX Terminal Control Definitions.
#include <unistd.h>			// UNIX Standard Definitions.
#include <errno.h>			// ERROR Number Definitions.
#include <pthread.h>
#include <sys/select.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *bitarr = NULL;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize){
    bitarr = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    int evenmask = 1;
    int oldmask = 2;
    int cnt =1;
    while(1){
        evenmask = evenmask|(1<<(2*cnt));
        oldmask = oldmask|(2<<(2*cnt));
        if((evenmask>1000 )&&(oldmask>1000))
            break;
        cnt++;
    }
    printf("eveen mask =%x old mask=%x\n",evenmask,oldmask);

    int bitcnt = 0;
    int even = n&evenmask;
    int old = n&oldmask;
    while(even){
        if(even&1){
            bitcnt++;
        }
        even = even>>1;
    }
    bitarr[0] = bitcnt;
    bitcnt = 0;
    while(old){
        if(old&1){
            bitcnt++;
        }
        old = old>>1;
    }
    bitarr[1] = bitcnt;  
    return bitarr;
}

int main(int argc, char** argv )
{
    //int nums[] = {4,1,2,1,2};
    //int len = sizeof(nums)/sizeof(int);
    int num = atoi(argv[1]);
    int len = 0;
    int *arr = evenOddBit(num,&len);

    for (int i = 0;i<len;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");

    if(arr)
        free(arr);

    return 0;
}

