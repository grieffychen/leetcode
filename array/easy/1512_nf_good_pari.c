/*
1512. Number of Good Pairs
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

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
#define bruceforce 0
#if bruceforce
int numIdenticalPairs(int* nums, int numsSize){
    int cnt = 0;
    for(int i = 0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i] == nums[j])
                cnt++;
        }
    }
    
    return cnt;
}
#else
int numIdenticalPairs(int* nums, int numsSize){
    int N[101] = {};

    for(int i = 0;i<numsSize;i++)
        N[nums[i]]++;
    
    int cnt = 0;
    for(int i=1;i<101;i++){
        if(N[i]!=0){
            cnt = cnt+N[i]*(N[i]-1)/2;
        }
    }

    return cnt;
}
#endif

int main(int argc, char** argv)
{
    int nums[] = {1,2,3,1,1,3};
    int numlen = sizeof(nums)/sizeof(int);
    for(int i =0;i<numlen;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");

    int nfpair=numIdenticalPairs(nums,numlen);
    printf("num of pari=%d\n",nfpair);
    return 0;
}
