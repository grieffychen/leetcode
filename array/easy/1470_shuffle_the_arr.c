/*
1470. Shuffle the Array
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
 

Constraints:

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3
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
#define bf 1

#if bf
int *retarr=NULL;
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    retarr = (int*) malloc(n*2*sizeof(int));
    *returnSize = 2*n;
    for(int i =0;i<n;i++){
        retarr[i*2] = nums[i];
        retarr[i*2+1] = nums[n+i];
    }
    return retarr;
}
#endif

int main(int argc, char** argv)
{
    int nums[] = {2,5,1,3,4,7};
    int n = sizeof(nums)/sizeof(int)/2;
    for(int i =0;i<n*2;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
#if bf
    int retlen;
    int *res = shuffle(nums,n*2,n,&retlen);
    for(int i =0;i<n*2;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    if(retarr)
        free(retarr);
#endif

    return 0;
}
