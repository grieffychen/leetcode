/*
2859. Sum of Values at Indices With K Set Bits
You are given a 0-indexed integer array nums and an integer k.

Return an integer that denotes the sum of elements in nums whose corresponding indices have exactly k set bits in their binary representation.

The set bits in an integer are the 1's present when it is written in binary.

For example, the binary representation of 21 is 10101, which has 3 set bits.
 

Example 1:

Input: nums = [5,10,1,5,2], k = 1
Output: 13
Explanation: The binary representation of the indices are: 
0 = 0002
1 = 0012
2 = 0102
3 = 0112
4 = 1002 
Indices 1, 2, and 4 have k = 1 set bits in their binary representation.
Hence, the answer is nums[1] + nums[2] + nums[4] = 13.
Example 2:

Input: nums = [4,3,2,1], k = 2
Output: 1
Explanation: The binary representation of the indices are:
0 = 002
1 = 012
2 = 102
3 = 112
Only index 3 has k = 2 set bits in its binary representation.
Hence, the answer is nums[3] = 1.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 105
0 <= k <= 10

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

#define bforce  1

#if bforce
int sumIndicesWithKSetBits(int* nums, int numsSize, int k){

    int sum =0;
    int bitset=0;
    for (int i=0;i<numsSize;i++){
        bitset = 0;
        int idx = i;
        while(idx>0){
            if(idx&1)
                bitset++;
            idx=idx>>1;
        }
        if(bitset==k)
        sum+=nums[i];
    }

    return sum;
}
#endif

int main(int argc, char** argv)
{
    int nums[] = {5,10,1,5,2};
    int k = 1;
    int len = sizeof(nums)/sizeof(int);
    for(int i =0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");


    int sum = sumIndicesWithKSetBits(nums,len,k);
    printf("sum =%d\n",sum);
    return 0;
}
