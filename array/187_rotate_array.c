/*

189. Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105


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

void rotate(int* nums, int numsSize, int k) {
    int *tmp = (int*) malloc(sizeof(int)*numsSize);
    for(int i =0;i<numsSize;i++){
        tmp[(i+k)%numsSize] = nums[i];
    }
    for(int i = 0;i<numsSize;i++)
        nums[i] = tmp[i];
    if(tmp)
        free(tmp);
}


int main(int argc, char** argv)
{   
    int nums[] = {1,2,3,4,5,6,7};
    int k = 3;
    int len = sizeof(nums)/sizeof(nums[0]);

    for(int i =0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");

    rotate(nums,len,k);
    for(int i =0;i<len;i++)
        printf("%d ",nums[i]);
    printf("\n");
    return 0;

}
