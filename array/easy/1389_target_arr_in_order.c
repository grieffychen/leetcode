/*
1389. Create Target Array in the Given Order

Given two arrays of integers nums and index. Your task is to create target array under the following rules:

Initially target array is empty.
From left to right read nums[i] and index[i], insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.

It is guaranteed that the insertion operations will be valid.

 

Example 1:

Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
Example 2:

Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
Example 3:

Input: nums = [1], index = [0]
Output: [1]
 

Constraints:

1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i
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
int* insertarr(int *targetarr, int arrlen,int pos,int val){

    for(int i = arrlen-1;i>pos;i--){
        targetarr[i] = targetarr[i-1];
    }
    targetarr[pos] = val;

    return targetarr;
}

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *tararr = (int*) malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;

    for(int i = 0;i<numsSize;i++){
        tararr = insertarr(tararr,numsSize,index[i],nums[i]);
    }

    return tararr;
}

int main(int argc, char** argv)
{
    int nums[] = {0,1,2,3,4};
    int index[] = {0,1,2,2,1};
    int numlen = sizeof(nums)/sizeof(int);
    int idxeln = sizeof(index)/sizeof(int);
    for(int i=0;i<numlen;i++)
        printf("%d ",nums[i]);
    printf("\n");
    for(int i=0;i<idxeln;i++)
        printf("%d ",index[i]);
    printf("\n");    
    int retlen = 0;

    int *resarr = createTargetArray(nums,numlen,index,idxeln,&retlen);
    if(resarr){
        for(int i=0;i<retlen;i++)
            printf("%d ",resarr[i]);
        printf("\n");       
        free(resarr);
    }

    return 0;
}
