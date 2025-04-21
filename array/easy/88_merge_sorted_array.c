/*

88. Merge Sorted Array


You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109



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

void swap(int *a,int* b)
{
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*b)^(*a);
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    for(int idx2 = 0;idx2<n;idx2++){
        nums1[m+idx2] = nums2[idx2];
        int idx1 = m+idx2;
        while((idx1>0)&&(nums1[idx1]<nums1[idx1-1])){
            swap(&nums1[idx1],&nums1[idx1-1]);
            idx1--;
        }
    }
}


int main(int argc, char** argv)
{   
    //int nums1[] = {1,2,3,0,0,0};
    //int nums2[] = {2,5,6};
    //int nums1[] = {0};
    //int nums2[] = {1};
    int nums1[] = {4,5,6,0,0,0};
    int nums2[] = {1,2,3};    

    int nums1Size = sizeof(nums1)/sizeof(nums1[0]);
    int nums2Size = sizeof(nums2)/sizeof(nums2[0]);
    int m = nums1Size-nums2Size;
    int n = nums2Size;
    printf("%d %d\n",m,n);
    merge(nums1,nums1Size,m,nums2,nums2Size,n);

    for(int i = 0;i<(m+n);i++){
        printf("%d ",nums1[i]);
    }
    printf("\n");

    return 0;

}
