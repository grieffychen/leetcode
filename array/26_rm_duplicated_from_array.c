/*
26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

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

int removeDuplicates(int* nums, int numsSize){
    //int new_size = numsSize;
    int i_insert = 0;
    int i_idx = 0;
    int i_scandup =i_idx+1;
    while(i_idx<numsSize){

        while (i_scandup < numsSize &&(nums[i_idx] == nums[i_scandup]))
        {
            i_scandup++;
        }
        nums[i_insert] = nums[i_scandup-1];
        i_idx = i_scandup;
        i_insert++;
        i_scandup++;
        
    }

    
    
    return i_insert;
}


int main(int argc, char** argv)
{
    int nums[] = {0,0,1,1,1,2,2,3,3,4} ; 
    int len = sizeof(nums)/sizeof(int); 
    for(int i = 0 ;i< len ;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
    printf("remove duplicate\n");
    int new_len = removeDuplicates(nums,len);
        for(int i = 0 ;i< new_len ;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");


    return 0;
}
