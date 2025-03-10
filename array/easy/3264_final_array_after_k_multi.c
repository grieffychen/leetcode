/*
3264. Final Array State After K Multiplication Operations I
You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

 

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]
Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5

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
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    *returnSize = numsSize;
    int *ansarr= (int*)malloc(sizeof(int)*numsSize);
    memcpy(ansarr,nums,numsSize*sizeof(int));
    //int min = INT_MAX;
    for(int i =0;i<k;i++){
        int min = INT_MAX;
        int minidx = 0;
        for(int i =0;i<numsSize;i++){
            if(ansarr[i]<min){
                min = ansarr[i];
                minidx = i;
            }
        }
        ansarr[minidx] = min*multiplier;
    }
    return ansarr;
}


int main(int argc, char** argv)
{
    int nums[] = {2,1,3,5,6};
    int k = 5;
    int multi=2;
    int len = sizeof(nums)/sizeof(int);
    int retlen = 0;
    int *ansarr =getFinalState(nums,len,k,multi,&retlen);

    if(ansarr){
        for(int i = 0;i< retlen;i++){
            printf("%d ",ansarr[i]);
        }
        printf("\n");
        free(ansarr);
    }
    return 0;
}
