/*
1920. Build Array from Permutation
Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

 

Example 1:

Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
Example 2:

Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
The elements in nums are distinct.    

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
#define bit    1

#if bit
int* buildArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    for(int i = 0 ;i<numsSize;i++){
        nums[i]+=(nums[nums[i]]&0x0000ffff)<<16;
    }
    for(int i = 0;i<numsSize;i++)
        nums[i] = nums[i]>>16;
    return nums;
}
#else

int *retarr =NULL;

int* buildArray(int* nums, int numsSize, int* returnSize){
    retarr = (int*) malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for(int i = 0;i<numsSize;i++){
        retarr[i] = nums[nums[i]];
    }
    return retarr;
}
#endif
int main(int argc, char** argv)
{
    int nums[] ={5,0,1,2,3,4};
    int numlen = sizeof(nums)/sizeof(int);
    int retlen=0;
    for(int i = 0;i<numlen;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    
#if bit
    int *retarr = buildArray(nums,numlen,&retlen);
    for(int i = 0;i<retlen;i++){
        printf("%d ",retarr[i]);
    }
    printf("\n");
#else
    retarr = buildArray(nums,numlen,&retlen);
    for(int i = 0;i<retlen;i++){
        printf("%d ",retarr[i]);
    }
    printf("\n");

    if(retarr)
        free(retarr);
#endif        
    return 0;
}
