/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105




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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmpfun(const void *a, const void *b){
    int  c = *(int*)a;
    int  d = *(int*)b;
    if((c-d)>0)
        return 1;
    else if((c-d)<0)
        return -1;
    else  
        return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ansarr = (int**) malloc(sizeof(int*)*1);
    *returnSize = 0;
    //for(int i =0;i<1;i++)
    //    *ansarr[i] = (int *)malloc(sizeof(int)*3);
    int idx = 0;
    qsort(nums,numsSize,sizeof(int),cmpfun);
    for(int i =0;i<numsSize;i++)
        printf("%d ",nums[i]);
    printf("\n");
    for (int i = 0 ;i<numsSize;i++){
        if((i>0)&&(nums[i]==nums[i-1]))
            continue;
        int left = i+1;
        int right = numsSize-1;
        while(left<right){
            int sum = nums[i] + nums[left]+ nums[right];
            if(sum == 0){
                int *subans = (int*) malloc(3*sizeof(int));
                subans[0] = nums[i];
                subans[1] = nums[left];
                subans[2] = nums[right];
                ansarr[idx] = subans;
                (*returnColumnSizes)[idx] = 3;
                idx++;
                ansarr =(int**) realloc(ansarr,sizeof(int*)*(idx+1)); 
                while((left<right)&&(nums[left]==nums[left+1]))
                    left++;
                while((left<right)&&(nums[right]==nums[right-1]))
                    right--;
                left++;
                right--;
            }else if(sum <0){
                left++;
            }else{
                right--;
            }

        }
    }  
    *returnSize = idx;

    return ansarr;
}


int main(int argc, char** argv)
{
    //int nums[] = {-1,0,1,2,-1,-4};
    int nums[] = {1,-1,-1,0};
    int len = sizeof(nums)/sizeof(int);
    //int *retcol = (int*) malloc(len*sizeof(int));
    int *retcol = (int*) calloc(len,sizeof(int));
    for(int i = 0;i< len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    int retlen = 0;

    int** ans = threeSum(nums,len,&retlen,&retcol);
    printf("retlen =%d\n",retlen);
#if 1    
    for (int i =0;i<retlen;i++){
        printf("col %d=%d\n",i,retcol[i]);
    }

#if 1    
    for (int i =0;i<retlen;i++){
        for(int j =0;j<retcol[i];j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
#endif    
    for(int i = 0;i<retlen;i++)
        free(ans[i]);
    free(ans);
    if(retcol)
        free(retcol);
#endif
    return 0;
}
