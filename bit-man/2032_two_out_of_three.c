/*
two out of three

Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that are present in at least two out of the three arrays. You may return the values in any order.
 

Example 1:

Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
Example 2:

Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
Output: [2,3,1]
Explanation: The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
Example 3:

Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
Output: []
Explanation: No value is present in at least two arrays.
 

Constraints:

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100


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
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    int *tbl = (int*) malloc(sizeof(int)*101);
    memset(tbl,0,sizeof(int)*101);
    for(int i = 0;i<nums1Size;i++)
        tbl[nums1[i]] = tbl[nums1[i]]|(1<<0);
    for(int i = 0;i<nums2Size;i++)
        tbl[nums2[i]] = tbl[nums2[i]]|(1<<1);
    for(int i = 0;i<nums3Size;i++)
        tbl[nums3[i]] = tbl[nums3[i]]|(1<<2);       

    int *ans = (int*)malloc(sizeof(int)*101);
    int idx = 0;
    for(int i = 0;i<101;i++)
        if((tbl[i] == 3)||(tbl[i]==5)||(tbl[i]==6)||(tbl[i]==7)){
            ans[idx] = i;     
            idx++;
        }
    if(tbl)
        free(tbl);
    *returnSize = idx;
    return ans;
}


int main(int argc, char** argv)
{
    return 0;
}

