/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
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


#define MAX(a,b) (a>b?a:b)
int lengthOfLIS(int* nums, int numsSize) {
    int *dp = (int*)malloc(sizeof(int)*numsSize);
    for (int i =0;i<numsSize;i++)
        dp[i] = 1;

    for(int i =0;i<numsSize;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i])
                dp[i] = MAX(dp[i],dp[j]+1);
        }
    }
    int max = 0;
    for(int i =0;i<numsSize;i++)
        max=MAX(max,dp[i]);
    
    return max;   
}

int main(const int argc, const char **argv)
{
    int nums[] = {10,9,2,5,3,7,101,18};
    int len = sizeof(nums)/sizeof(int);

    int lis = lengthOfLIS(nums,len);
    printf("LIS=%d\n",lis);
    return 0;
}