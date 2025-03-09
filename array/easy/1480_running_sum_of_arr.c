/*
1480. Running Sum of 1d Array
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
 

Constraints:

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6
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
int* runningSum(int* nums, int numsSize, int* returnSize){
    int *sumarr = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
#if 1
    int sum = 0;
    for(int i= 0;i<numsSize;i++){
        sum=sum+nums[i];
        sumarr[i] = sum;
    }
    return sumarr;
#else
    for(int i=0;i<numsSize;i++){
        int sum = 0;
        for(int j=0;j<=i;j++)
            sum+=nums[j];
        sumarr[i] = sum;
    }

    return sumarr;
#endif    
}

int main(int argc, char** argv)
{
    int nums[] = {3,1,2,10,1};
    int numlen = sizeof(nums)/sizeof(int);
    int retlen = 0;
    for(int i =0;i<numlen;i++)
        printf("%d ",nums[i]);
    printf("\n");
    int *sumarr = runningSum(nums,numlen,&retlen);
    if(sumarr){
        for(int i =0;i<retlen;i++)
            printf("%d ",sumarr[i]);
        printf("\n");
        free(sumarr);
    }
    return 0;
}
