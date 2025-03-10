/*
260. Single Number III


Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1


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


int* singleNumber(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2;
    int *ansarr = (int*) malloc(sizeof(int)*2);
    ansarr[0] = 0;
    ansarr[1] = 0;
    int xorval = 0;
    for(int i = 0;i<numsSize;i++){
        xorval = xorval^nums[i];
    }
    int bitflag = xorval&(-(unsigned int)xorval);
    //printf("bit flag=%d\n",bitflag);
    for(int i = 0;i<numsSize;i++){
        if(nums[i]&bitflag){
            ansarr[0] = ansarr[0] ^nums[i];
        }
    }
    ansarr[1] = xorval^ansarr[0];

    return ansarr;
}

int main(int argc, char** argv)
{
    int nums[] = {1,2,1,3,2,5};
    int len = sizeof(nums)/sizeof(int);
    int retlen = 0;
    for(int i =0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");    
    int *ansarr=singleNumber(nums,len,&retlen);
    if(ansarr){
        for(int i = 0;i<retlen;i++){
            printf("%d ",ansarr[i]);
        }
        printf("\n");
        free(ansarr);
    }
    return 0;
}

