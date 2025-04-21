/*

238. Product of Array Except Self


Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

/**
 * Note: The returned array must be malloced, assume caller calls free().
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



int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int *arr = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;

    arr[0] = 1;
    for(int i =1;i<numsSize;i++){
        arr[i] =arr[i-1]*nums[i-1];
    }

    int r = 1;
    for(int i = numsSize-1;i>=0;i--){
        arr[i]=arr[i]*r;
        r=r*nums[i];
    }

    return arr;    
}


int main(int argc, char** argv)
{   
    int nums[] = {1,2,3,4};
    //int nums[] ={-1,1,0,-3,3};
    int len = sizeof(nums)/sizeof(nums[0]);
    int retlen = 0;

    int *ansarr = productExceptSelf(nums,len,&retlen);
    if(ansarr){
        for(int i =0;i<retlen;i++)
            printf("%d ",ansarr[i]);
        printf("\n");
        free(ansarr);
    }
    return 0;
}
