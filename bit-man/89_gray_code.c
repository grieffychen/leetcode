/*

89. Gray Code

An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

 

Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]
 

Constraints:

1 <= n <= 16


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
int* grayCode(int n, int* returnSize) {
    int total = 1<<n;
    *returnSize = total;
    int *ansarr = (int*) malloc(total*sizeof(int));
    int pregray = 0;
    ansarr[0] = 0;
    for(int i = 1 ;i<total;i++){
        pregray = ansarr[i-1];
        if((i)%2 == 1){ //odd
            ansarr[i] = pregray^1;
        }else{//even
            int temp = pregray;
            int j = 0;
            while(temp){
                if(temp&1){
                    ansarr[i] = pregray^(1<<(j+1));
                    break;
                }
                j++;
                temp=temp>>1;
            }
        }
    }
    return ansarr;
}

int main(int argc, char** argv)
{
    int n = 2;
    //printf("%d %d\n",3,3&(-3));
    int retlen = 0;
    int *ans = grayCode(n,&retlen);

    for(int i = 0;i<retlen;i++){
        printf("%d \n",ans[i]);
    }
    if(ans)
        free(ans);
    return 0;
}

