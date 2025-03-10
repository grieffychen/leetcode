/*
2610. Convert an Array Into a 2D Array With Conditions

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

 

Example 1:

Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.
Example 2:

Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= nums.length


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
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *dict = (int*) calloc(201,sizeof(int));
    for(int i = 0;i<numsSize;i++){
        dict[nums[i]]++;
    }
    int rowcnt = 0;
    *returnColumnSizes = calloc(numsSize,sizeof(int));

    for(int i =0;i<numsSize;i++){
        printf("i=%d %d\n",i,(*returnColumnSizes)[i]);
    }


    int **ans = (int**)malloc(numsSize*sizeof(int*));
    for(int i = 0;i<numsSize;i++)
        ans[i] = (int *)malloc(sizeof(int)*numsSize);

    int total = 0;
    
    for(int i = 1;i<201;i++){
        printf("%d ",dict[i]);
        if(i%10==0)
            printf("\n");
    }

    while(total<numsSize){
        int colcnt = 0;
        for(int i = 1;i<201;i++){
            if(dict[i]!=0){
                ans[rowcnt][colcnt] = i;
                dict[i]--;
                colcnt++;
            }
        }
        total+=colcnt;
        printf("total =%d rowcnt =%d collen=%d\n",total,rowcnt,colcnt);
        //*(returnColumnSizes[rowcnt]) = colcnt;
        (*returnColumnSizes)[rowcnt] = colcnt;
        printf("%d %d \n",rowcnt,(*returnColumnSizes)[rowcnt]);
        rowcnt++;
        //printf("rowcnt=%d\n",rowcnt);
    }
    *returnSize = rowcnt;
    free(dict);
    return ans;
}


int main(int argc, char** argv)
{
    int nums[] = {1,3,4,1,2,3,1};
    int len = sizeof(nums)/sizeof(int);
    printf("len =%d \n",len);
    //int *retColSize = (int*) calloc(len,sizeof(int));
    int *retColSize = NULL;
    //int *retColSize =(int*) malloc(sizeof(int)*len);
    //memset(retColSize,0,sizeof(int)*len);
    //for(int i = 0;i<len;i++)
    //    printf("%d ",retColSize[i]);
    //printf("\n");
    int retRowlen = 0;

    int **ansarr = findMatrix(nums,len,&retRowlen,&retColSize);
    printf("test\n");
    for (int i = 0;i<retRowlen;i++){
        for(int j = 0;j<retColSize[i];j++){
            printf(" %d",ansarr[i][j]);
        }
        printf("\n");
    }
    if(retColSize)
        free(retColSize);
    for(int i = 0;i<len;i++)
        free(ansarr[i]);
    free(ansarr);
    return 0;
}
