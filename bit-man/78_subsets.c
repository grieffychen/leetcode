/*

78. Subsets

Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.



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
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1<<numsSize;
    *returnSize = total;
    int **ans = (int**) malloc(sizeof(int*)*total);
    *returnColumnSizes =(int*)malloc(sizeof(int)*total);
    //printf("total =%d\n",total);
    for(int i = 0;i<total;i++){
        ans[i] = (int*)malloc(sizeof(int)*numsSize);
        int nfelm = 0;
        int j = 0;
        int idx = i;
        printf("i=%d\n",i);
        while(idx){
            if(idx&1){
                ans[i][nfelm]=nums[j];
                nfelm++;
            }
            idx=idx>>1;
            j++;
        }
        (*returnColumnSizes)[i] = nfelm;
    }
    return ans;
}

int main(int argc, char** argv)
{
    int nums[] = {1,2,3};
    int len = sizeof(nums)/sizeof(int);
    int *retcol = NULL;
    int retlen = 0;
    for(int i =0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n======================\n");
    int **ans = subsets(nums,len,&retlen,&retcol);
    for(int i = 0;i<retlen;i++){
        for(int j =0;j<retcol[i];j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");

    }
    //printf("%d %d\n",2^len,1<<len);
    return 0;
}

