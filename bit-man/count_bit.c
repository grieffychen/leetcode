/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 10^5

e.g : consider 7 and 3

1 1 1
0 1 1

The number of set bits of number 7 is setBitsOf(3)+7%2


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




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize)
{
    for(int i = 0 ; i<=n;i++){
        int cnt = 0;
        //printf("%d\n",i);     
        int curval = i;  
        while(curval){
            if(curval&1)
                cnt++;
            curval=curval>>1;
        }
        returnSize[i] = cnt;
       
    }

    return returnSize;
}

int* countBits2(int n, int* returnSize)
{
    returnSize[0] = 0;
    for(int i = 1 ; i<=n;i++){
        returnSize[i] = returnSize[i/2] + i%2;

    }

    return returnSize;
}

int main(int argc, char** argv )
{
    int arrlen = atoi(argv[1]);
    int *bitcountarray =NULL;
    bitcountarray = (int*) malloc(sizeof(int)*(arrlen+1));
    printf("input %d\n",arrlen);
    //bitcountarray = countBits(arrlen,bitcountarray);
    bitcountarray = countBits2(arrlen,bitcountarray);
    printf("input %d\n",arrlen);
    for(int i = 0 ;i<arrlen+1;i++)
        printf(" %d",bitcountarray[i]);
    printf("\n");

    if(bitcountarray)
        free(bitcountarray);
    return 0;
}

