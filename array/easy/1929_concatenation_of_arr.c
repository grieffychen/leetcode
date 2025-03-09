/*
1929. Concatenation of Array

Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 

Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000

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

int *retarr =NULL;
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    *returnSize = 2*numsSize;
    //printf("%d\n",sizeof(nums));
    int memlen = 2*numsSize*sizeof(int);
    //retarr = (int*)malloc(sizeof(int)*(*returnSize));
    retarr = (int*)malloc(memlen);
    memcpy(retarr,nums,memlen/2);
    memcpy(retarr+numsSize,nums,memlen/2);
    return retarr;
}

#define memtest 1
#if memtest 
void memlentest(){
    int *intarr = (int*)malloc(sizeof(int)*4);
    char *chararr= (char*)malloc(sizeof(char)*4);

    printf("int pos\t char pos\n");
    for(int i = 0 ;i<4;i++){
        printf("%p\t %p\n",intarr+i,chararr+i);
    }
    printf("\n");
    if(intarr)
        free(intarr);
    if(chararr)
        free(chararr);
}

#endif
int main(int argc, char** argv)
{
    int nums[] = {1,3,2,1};
    //printf("%d %d\n",sizeof(nums),sizeof(int));
    int numlen = sizeof(nums)/sizeof(int);
    int retlen = 0;
    for(int i = 0;i<numlen;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    retarr = getConcatenation(nums,numlen,&retlen);
    for(int i = 0;i<retlen;i++){
        printf("%d ",retarr[i]);
    }
    printf("\n");

    memlentest();
    if(retarr)
        free(retarr);   
    return 0;
}
