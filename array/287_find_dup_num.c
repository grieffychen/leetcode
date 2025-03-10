/*

287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

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


int findDuplicate(int* nums, int numsSize) {
    int *map = (int *) malloc(sizeof(int)*numsSize);
    memset(map,0,sizeof(int)*numsSize);

    for(int i = 0;i<numsSize;i++){
        ++map[nums[i]];
    }
    int val = 0;
    for(int i =0;i<numsSize;i++){
        if(map[i]>1)
            val = i;
    }
    free(map);
    return val;
}


int main(int argc, char** argv)
{
    int nums[] = {1,3,4,2,2};
    int len = sizeof(nums)/sizeof(int);
    for(int i =0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");    
    int ans = findDuplicate(nums,len);
    printf("%d\n",ans);
    return 0;
}
