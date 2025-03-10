/*

16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104


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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int cmpfun(const void *a, const void *b){
    int  c = *(int*)a;
    int  d = *(int*)b;
    if((c-d)>0)
        return 1;
    else if((c-d)<0)
        return -1;
    else  
        return 0;
}

#if 1
int threeSumClosest(int* nums, int numsSize, int target) {
    int sum  = 0;
    //int diff = 0;
    int closest = INT_MAX;
    int anssum  =0;
    qsort(nums,numsSize,sizeof(int),cmpfun);
    for (int i = 0;i<numsSize-2;i++){
        int left = i+1;
        int right = numsSize-1;
        while(left<right){
            sum = nums[i]+nums[left]+nums[right];
            if(sum == target){
                return sum;
            }            
            if(sum<target){
                if(abs(sum-target) <closest){
                    closest = abs(sum-target);
                    anssum = sum;
                }
                left++;
            }else{
                if(abs(sum-target) <closest){
                    closest = abs(sum-target);
                    anssum = sum;
                }
                right--;
            }
        }
#if 0        
        sum = nums[i] + nums[left]+nums[right];
        if(abs(sum-target)<closest){
            closest = abs(sum-target);
            anssum = sum;
        }
        while((left<right)&&())
#endif
    }

    return anssum;
}
#else
int threeSumClosest(int* nums, int numsSize, int target) {
    int sum  = 0;
    int diff = 0;
    int closest = INT_MAX;
    int anssum  =0;
    for (int i = 0;i<numsSize-2;i++){
        for(int j = i+1;j<numsSize-1;j++){
            for(int k = j+1;k<numsSize;k++){
                sum = nums[i]+nums[j]+nums[k];
                
                diff = abs(sum-target);
                printf("sum=%d diff=%d closet =%d\n",sum,diff,closest);
                if(diff == 0){
                    return sum;
                }else{
                    if(diff<closest){
                        closest = diff;
                        anssum = sum;
                    }
                }
            }
        }
    }

    return anssum;
}
#endif

int main(int argc, char** argv)
{
    int nums[] = {-1,2,1,-4};
    int target = 1;
    int len = sizeof(nums)/sizeof(int);

    int ans = threeSumClosest(nums,len,target);
    for(int i = 0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");
    printf("close =%d\n",ans);
    return 0;
}
