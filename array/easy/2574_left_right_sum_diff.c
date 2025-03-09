/*

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

#define bforce  0

#if bforce
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize){
    int *diff = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;

    for(int i =0 ;i<numsSize;i++){
        int l_sum =0;
        int r_sum =0;
        for(int j=0;j<numsSize;j++){
            if(j<i)
                l_sum+=nums[j];
            else if(j>i)
                r_sum+=nums[j];
        }
        diff[i] = abs(l_sum-r_sum);
    }
    
    return diff;
}
#else
int* leftRightDifference(int* nums, int numsSize, int* returnSize){
    int *diff = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int lsum[numsSize];
    int rsum[numsSize];
    memset(lsum,0,sizeof(lsum));
    memset(rsum,0,sizeof(rsum));
    int ls = 0;
    int rs = 0;
    lsum[0] = 0;
    rsum[numsSize-1] =0;
    int j=numsSize-2;
    for(int i =1;i<numsSize;i++,j--){
        ls+=nums[i-1];
        lsum[i]=ls;
        rs+=nums[j+1];
        rsum[j]=rs;
    }
    for (int i =0;i<numsSize;i++)
        printf("%d ",lsum[i]);
    printf("\n");
    for (int i =0;i<numsSize;i++)
        printf("%d ",rsum[i]);
    printf("\n");

    for(int i= 0;i<numsSize;i++)
        diff[i] = abs(lsum[i]-rsum[i]);

    return diff;
}
#endif

int main(int argc, char** argv)
{
    int nums[] = {10,4,8,3};
    int len = sizeof(nums)/sizeof(int);
    for(int i =0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    int retlen = 0;
    int *diffarr = leftRightDifference(nums,len,&retlen);

    if(diffarr){
        for (int i =0;i<retlen;i++)
            printf("%d ",diffarr[i]);
        printf("\n");

        free(diffarr);
    }

    return 0;
}
