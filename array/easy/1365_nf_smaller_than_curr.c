/*
1365. How Many Numbers Are Smaller Than the Current Number
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
 

Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100

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
#define bforce  1

#if bforce
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *resarr = (int*) malloc(sizeof(int)*numsSize);
    for(int i =0;i<numsSize;i++){
        int cnt = 0;
        for(int j = 0;j<numsSize;j++){
            if((j!=i )&&(nums[i]>nums[j]))
                cnt++;
        }
        resarr[i] = cnt;
    }
    return resarr;
}
#endif


int main(int argc, char** argv)
{
    int nums[] = {8,1,2,2,3};
    int len = sizeof(nums)/sizeof(int);
    int retlen = 0;
    for(int i =0 ;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");
    int *retarr = smallerNumbersThanCurrent(nums,len,&retlen);

    if(retarr){
        for(int i =0 ;i<len;i++)
            printf("%d ",retarr[i]);
        printf("\n");
        free(retarr);
    }
    
    return 0;
}
