/*

31. Next Permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

158476531



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

void swap(int *nums , int i,int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void reverse(int *nums, int start,int numsSize)
{
    int i = start;
    int j = numsSize-1;
    while(i<j){
        swap(nums,i,j);
        i++;
        j--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    
    int i = numsSize -2;
    while((i>=0)&&(nums[i]>=nums[i+1])){
        i--;
    }   
    //decrease order , reverse array
    if(i <0){
        reverse(nums,0,numsSize);
        return;
    }
    int j = numsSize -1;
    while((j>=0)&&(nums[j]<=nums[i])){
        j--;
    }
    swap(nums,i,j);
    reverse(nums,i+1,numsSize);
}

int main(int argc, char** argv)
{
    int nums[] = {1,2,3};
    //int nums[] = {1,5,8,4,7,6,5,3,1};
    int len = sizeof(nums)/sizeof(int);
    for(int i = 0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");    
#if 1
    nextPermutation(nums,len);
    for(int i = 0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");   
#endif
    return 0;
}
