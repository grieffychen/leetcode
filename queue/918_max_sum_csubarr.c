/*
918. Maximum Sum Circular Subarray
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104

 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>                      // File Control Definitions.
#include <termios.h>            // POSIX Terminal Control Definitions.
#include <unistd.h>                     // UNIX Standard Definitions.
#include <errno.h>                      // ERROR Number Definitions.
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

int maxSubarraySumCircular(int* nums, int numsSize) {
    int maxsum = INT_MIN;
    int cursum = 0;
    int total = 0;
    for(int i = 0;i<numsSize;i++){
        cursum+=nums[i];
        if(cursum<nums[i])
            cursum = nums[i];
        maxsum = maxsum>cursum?maxsum:cursum;
        //printf("max sum=%d\n",maxsum);
        total+=nums[i];
    }
    int minsum = INT_MAX;
    cursum = 0;
    for (int i =0;i<numsSize;i++){
        cursum+=nums[i];
        if(cursum>nums[i])
            cursum=nums[i];
        minsum=minsum<cursum?minsum:cursum;
        //printf("min sum=%d\n",minsum);
    }

    int max =0;
    if(total-minsum ==0) 
        max=maxsum;
    else
        max = maxsum>(total-minsum)?maxsum:(total-minsum);

    return max;
}

int main(int argc, char**argv)
{
    //int nums[] = {5,-3,5};
    //int nums[] = {1,-2,3,-2};
    int nums[] = {-3,-2,-3};
    int len = sizeof(nums)/sizeof(int);
    printf("len =%d\n",len);
    int max = maxSubarraySumCircular(nums,len);
    printf("max =%d\n",max);

    return 0;
}
