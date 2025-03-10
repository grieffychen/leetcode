/*

90. Subsets II

Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10



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


int cmpfun(const void* a,const void* b){
    int c = *(int*)a;
    int d = *(int*)b;
    if(c>d)
        return 1;
    else if(c<d)
        return -1;
    else
        return 0;
}

#if 1

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1<<numsSize;
    //qsort(nums,numsSize,sizeof(int),cmpfun);
    qsort(nums,numsSize,sizeof(int),cmpfun);
    for(int i =0;i<numsSize;i++)
        printf("%d ",nums[i]);
    printf("\n======================\n");    
    int **ansarr = (int**) malloc(total*sizeof(int*));
    *returnColumnSizes = (int*) malloc(sizeof(int)*total);
    for (int i =0;i<total;i++){
        int nfitem = 0;
        int idx = i;
        int j =0;
        ansarr[i] =(int*) malloc(sizeof(int)*numsSize);
        while(idx){;
            if(idx&1){
                ansarr[i][nfitem]=nums[j];
                nfitem++;
            }
            j++;
            idx>>=1;
        }
        (*returnColumnSizes)[i] = nfitem;
    }
    *returnSize = total;
    return ansarr;
}


int main(int argc, char** argv)
{
    int nums[] = {1,2,2};
    int len = sizeof(nums)/sizeof(int);
    int *retcol = NULL;
    int retlen = 0;

    int **ans = subsetsWithDup(nums,len,&retlen,&retcol);
#if 1    
    for(int i = 0;i<retlen;i++){
        for(int j =0;j<retcol[i];j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");

    }    
    if(retcol)
        free(retcol);

    for(int i = 0;i<retlen;i++){
        free(ans[i]);
    }
    free(ans);
#endif
    return 0;
}
#else
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1<<numsSize;
    //qsort(nums,numsSize,sizeof(int),cmpfun);
    qsort(nums,numsSize,sizeof(int),cmpfun);
    for(int i =0;i<numsSize;i++)
        printf("%d ",nums[i]);
    printf("\n======================\n");    
    int **ansarr = (int**) malloc(total*sizeof(int*));
    *returnColumnSizes = (int*) malloc(sizeof(int)*total);
    
    for(int i = 0;i<total;i++){
        ansarr[i] = (int*) malloc(sizeof(int)*numsSize);
        int bitval = i;
        int sublen = 0;
        int bitidx = 0;
        while(bitval){
            
            if(bitval&1){
                ansarr[i][sublen] = nums[bitidx];
                sublen++;
            }
            bitidx++;
            bitval = bitval>>1;
        }
        (*returnColumnSizes)[i] = sublen;
    }
    *returnSize = total;
    return ansarr;
}


int main(int argc, char** argv)
{
    int nums[] = {1,2,2};
    int len = sizeof(nums)/sizeof(int);
    int *retcol = NULL;
    int retlen = 0;
    for(int i =0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n======================\n");
    int **ans = subsetsWithDup(nums,len,&retlen,&retcol);
#if 1    
    for(int i = 0;i<retlen;i++){
        for(int j =0;j<retcol[i];j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");

    }    
    if(retcol)
        free(retcol);

    for(int i = 0;i<retlen;i++){
        free(ans[i]);
    }
    free(ans);
#endif    
    //printf("%d %d\n",2^len,1<<len);
    return 0;
}

#endif