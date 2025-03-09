/*
1313. Decompress Run-Length Encoded List
We are given a list nums of integers representing a list compressed with run-length encoding.

Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.

Return the decompressed list.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4] is [2,4,4,4].
Example 2:

Input: nums = [1,1,2,3]
Output: [1,3,3]
 

Constraints:

2 <= nums.length <= 100
nums.length % 2 == 0
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
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int total = 0;
    for(int i =0;i<numsSize;i+=2){
        total+=nums[i];
    }
    *returnSize = total;
    int *rlarr = malloc(total*sizeof(int));
    int ridx = 0;
    int pos = 0;
    for(int i = 0;i<numsSize;i+=2){
        int val = nums[i+1];
        pos+=nums[i];
        while(ridx<pos)
            rlarr[ridx++]=val;
    }

    return rlarr;
}

int main(int argc, char** argv)
{
    int nums[] = {1,2,3,4};
    int numlen = sizeof(nums)/sizeof(int);

    for(int i = 0;i<numlen;i++)
        printf("%d ",nums[i]);
    printf("\n");
    int retlen = 0;
    int *retarr = decompressRLElist(nums,numlen,&retlen);
    if(retarr){
        for(int i = 0;i<retlen;i++)
            printf("%d ",retarr[i]);
        printf("\n");        
        free(retarr);
    }

    return 0;
}
