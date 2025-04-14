/*

55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105


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

bool canJump(int* nums, int numsSize) {
    if(nums[0] == 0)
        return false;
    //char *dp = (char*)malloc(sizeof(char)*numsSize);
    char *dp = (char*)calloc(numsSize,sizeof(char));
    dp[0] = 1;
    for(int i = 1;i<numsSize;i++){
        for(int j = i;j>0;j--){
            if((dp[j-1]==1) &&(i-(j-1)<=nums[j-1])){
                dp[i] = 1;
                break;
            }
        }
    }
    for(int i = 0;i<numsSize;i++){
        printf(" %d",dp[i]);
    }
    printf("\n");

    bool ans = dp[numsSize-1]==1?true:false;
    if(dp)
        free(dp);
    return ans;
}


bool canJump2(int* nums, int numsSize) {
    int curpos = numsSize-2;
    int goal = numsSize-1;

    while(curpos>=0){
        if(curpos+nums[curpos]>=goal){
            goal = curpos;
        }
        curpos--;
    }

    return goal == 0;
}

int main(int argc, char** argv)
{   

    //int nums[] = {2,3,1,1,4};
    int nums[] = {3,2,1,0,4};
    int len = sizeof(nums)/sizeof(nums[0]);
    bool isjump = canJump(nums,len);
    printf("can jump=%s\n",isjump?"true":"false");
    isjump = canJump2(nums,len);
    printf("can jump=%s\n",isjump?"true":"false");
    return 0;

}
