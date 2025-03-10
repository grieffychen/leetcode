/*

137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.


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

int singleNumber(int* nums, int numsSize) {

    int ans = 0;
#if 1
    for(int i=0;i<32;i++){
        int sumbits = 0;
        for(int j = 0;j<numsSize;j++){
            if((nums[j]>>i)&1){
                sumbits++;
            }
        }
        if(sumbits%3==1)
            ans =ans|(1<<i);
    }
#else
    for(int i =0;i<32;i++){
        int64_t mask = 1<<i;
        int sumbits = 0;
        for(int j = 0;i<numsSize;i++){
            if(nums[j]&mask){
                sumbits++;
            }
        }
        if(sumbits%3==1){
            ans =ans|mask;
        }
    }
#endif    
    return ans;
}

int main(int argc, char** argv)
{
    //int nums[] = {0,1,0,1,0,1,99};
    int nums[] = {-2,-2,1,1,4,1,4,4,-4,-2};
    int len = sizeof(nums)/sizeof(int);
    printf("%d\n",1<<31);
    for (int i = 0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");

    int single = singleNumber(nums,len);
    printf("single =%d\n",single);

    return 0;
}

