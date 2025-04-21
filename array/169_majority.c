/*

169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


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


int majorityElement(int* nums, int numsSize) {
    int major = nums[0];
    int count =1;
    for(int i = 1;i<numsSize;i++){
        if(count ==0)
            major=nums[i];
        if(major==nums[i])
            count++;
        else
            count--;
    }
    return major;
}

int main(int argc, char** argv)
{   
    int nums[] = {2,2,1,1,1,2,2};
    int len = sizeof(nums)/sizeof(nums[0]);

    for(int i =0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");

    int m = majorityElement(nums,len);
    printf("major=%d\n",m);
    return 0;

}
