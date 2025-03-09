/*
167. Two Sum II - Input Array Is Sorted
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

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
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ans = (int*)malloc(sizeof(int)*2);
    int l_idx = 0;
    int r_idx = numbersSize -1;
    while(l_idx<r_idx){
        int sum = numbers[l_idx]+numbers[r_idx];
        if(sum==target){
            ans[0] = l_idx+1;
            ans[1] = r_idx+1;
            *returnSize = 2;
            return ans;
        }
        if(sum<target)
            l_idx++;
        else
            r_idx--;

    }
    
    return NULL;
}

int* twoSumBruceForce(int* numbers, int numbersSize, int target, int* returnSize){

    int *ans = (int*)malloc(sizeof(int)*2);

    for(int i = 0;i<numbersSize;i++){
        int search = target- numbers[i];
        for(int j = i+1;j<numbersSize;j++){
            if(numbers[j] == search){
                ans[0] = i+1;
                ans[1] = j+1;
                *returnSize = 2;
                return ans;
            }
        }
    }

    return NULL;
}



int main(int argc, char** argv)
{
    int nums[]={2,7,11,15};
    int len = sizeof(nums)/sizeof(int); 
    int target=9;
    for(int i = 0 ;i< len ;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    int retlen = 0;
    //int *arr = twoSumBruceForce(nums,len,target,&retlen);
    int *arr = twoSum(nums,len,target,&retlen);
    for(int i =0;i<retlen;i++)
        printf("%d ",arr[i]);
    printf("\n");
    free(arr);

    return 0;
}
