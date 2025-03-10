/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


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
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    //int *ans = (int*) malloc(sizeof(int)*2);
    int *ans = (int*) calloc(2,sizeof(int));
    //printf("%d %d\n",ans[0],ans[1]);
    for(int i = 0;i<numsSize;i++){
        for(int j = i+1;j<numsSize;j++){
            if((nums[i]+nums[j])==target){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}


int main(int argc, char** argv)
{
    int nums[] = {2,7,11,15};
    int len = sizeof(nums)/sizeof(int);
    int tar = 9;
    for (int i = 0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");
    printf("target=%d\n",tar);
    int retlen = 0;
    int *ans = twoSum(nums,len,tar,&retlen);
    printf("%d %d\n",ans[0],ans[1]);
    return 0;
}
