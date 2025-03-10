/*

2099. Find Subsequence of Length K With the Largest Sum


You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
 

Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length




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
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct pair {
    int val;
    int idx;
};

int cmp_num(const void *a,const void *b)
{
    struct pair pa =*((const struct pair*)a);
    struct pair pb =*((const struct pair*)b);
    return (pb.val-pa.val);
}

int cmp_idx(const void *a,const void *b)
{
    struct pair pa =*((const struct pair*)a);
    struct pair pb =*((const struct pair*)b);
    return (pa.idx-pb.idx);
}


int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    struct pair *parr = (struct pair*) malloc(sizeof(struct pair)*numsSize);
    for(int i =0;i<numsSize;i++){
        parr[i].idx =i;
        parr[i].val = nums[i];
    }
    qsort(parr,numsSize,sizeof(struct pair),cmp_num);
    for(int i =0;i<numsSize;i++){
        printf("[%d %d]\n",parr[i].idx,parr[i].val);
    }
    qsort(parr,k,sizeof(struct pair),cmp_idx);
    int *ans =(int*) malloc(sizeof(int)*k);

    for(int i= 0;i<k;i++){
        ans[i] = parr[i].val;
    }
    if(parr)
        free(parr);
    return ans;
}


int main(int argc, char** argv )
{
    int nums[] = {2,1,3,3};
    int k =2;
    int retlen =0 ;
    int len = sizeof(nums)/sizeof(int);
    for(int i =0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");

    int *ansarr = maxSubsequence(nums,len,k,&retlen);

    if(ansarr){
        for(int i =0;i<retlen;i++)
            printf("%d ",ansarr[i]);
        printf("\n");
        free(ansarr);
    }
	return 0;
}