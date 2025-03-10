/*


421. Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1

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


int findMaximumXOR(int* nums, int numsSize){
    int max = 0;
    for(int i =0;i<numsSize-1;i++){
        for (int j = 0;j<numsSize;j++){
            int xor = nums[i]^nums[j];
            max = max>xor?max:xor;
        }
    }

    return max;
}

int main(int argc, char** argv)
{
    //int nums[] = {3,10,5,25,2,8};
    int nums[] = {14,70,53,83,49,91,36,80,92,51,66,70};
    int len = sizeof(nums)/sizeof(int);
    int ans = findMaximumXOR(nums,len);
    printf("max xor =%d\n",ans);
    return 0;
}

