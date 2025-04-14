/*


45. Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

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

int jump(int* nums, int numsSize) {
    if(numsSize==1)
        return 0;
    int *dp = (int*)calloc(numsSize,sizeof(int));
    for(int i = 1;i<numsSize;i++){
        int minstep = INT_MAX;
        for(int j = i-1;j>=0;j--){
            if((i-j)<=nums[j]){
                int step = dp[j]+1;
                minstep=minstep<step?minstep:step;
            }
        }
        dp[i] = minstep;
    }
    int ans = dp[numsSize-1];
    if(dp)
        free(dp);
    return ans;
}

int main(int argc, char** argv)
{   
    //int nums[]= {2,3,1,1,4};
    int nums[]= {2,3,0,1,4};
    int len = sizeof(nums)/sizeof(nums[0]);
    int step = jump(nums,len);
    printf("step =%d\n",step);
    return 0;

}
