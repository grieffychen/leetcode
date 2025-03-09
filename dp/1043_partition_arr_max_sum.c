/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1
 

Constraints:

1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length

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

#define MAX(a,b) (a>b?a:b)
int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    int *dp = malloc(sizeof(int)*(arrSize+1));
    memset(dp,0,sizeof(int)*(arrSize+1));
    dp[0] = 0;
    printf("==================\n");
    for(int i = 1;i<=arrSize;i++){
        int maxsum = INT_MIN;
        int max = INT_MIN;
        for(int j = 1;(j<=k)&&(i-j>=0);j++){
            //int sum = dp[i-j]+arr[i-j+1]*j;
            max = MAX(max,arr[i-j]);
            int sum = dp[i-j]+max*j;
            maxsum=MAX(maxsum,sum);
            //m =max(m,sum);
            printf("j=%d sum=%d, max=%d\n",j,sum,maxsum);
        }
        dp[i] = maxsum;
        printf("dp[%d]=%d\n",i,dp[i]);
    }
    int max = dp[arrSize];
    if(dp)
        free(dp);
    return max;
}


int main(int argc, char** argv)
{
    int arr[] = {1,15,7,9,2,5,10};
    int k = 3;
    int max = maxSumAfterPartitioning(arr,sizeof(arr)/sizeof(int),k);
    printf("max=%d\n",max);

    return 0;
}