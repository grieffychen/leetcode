/*
 Sum of All Subset XOR Totals
 The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

 

Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
Example 2:

Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
Example 3:

Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.
 

Constraints:

1 <= nums.length <= 12
1 <= nums[i] <= 20

solution

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), total_subsets = 1<<n, sum = 0;
        for(int mask=0;mask<total_subsets;mask++){
            int sub_xor = 0;
            for(int i=0;i<n;i++){
                if(mask & 1<<i) sub_xor ^= nums[i];
            }
            sum += sub_xor;
        }
        return sum;
    }
};

C++ 3 easy understanding || Iterative || Recursive sol.

class Solution {
public:
    int findAllSubsetXor(int i, vector<int>& nums, int x) {
      if(i == nums.size()) return x;
      return findAllSubsetXor(i+1, nums, x ^ nums[i])+findAllSubsetXor(i+1, nums,x);
    }
    int subsetXORSum(vector<int>& nums) {
        return findAllSubsetXor(0,nums,0);
    }
};


class Solution {
public:
    int subsetXORSum(vector<int>& nums,int i=0,  int x=0) {
      if(i == nums.size()) return x;
      return subsetXORSum(nums,i+1,x ^ nums[i])+subsetXORSum(nums,i+1,x);
    }
};

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), totalSubsets = 1<<n, sum = 0;
        for(int mask=0;mask<totalSubsets;mask++){
            int subXor = 0,x=1;
            for(int i=0;i<n;i++){
                if(mask & x) subXor ^= nums[i];x<<=1;
            }
            sum += subXor;
        }
        return sum;
    }
};

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

int subsetXORSum(int* nums, int numsSize){
    int sum = 0;
    int xor = 0;
    for(int sub = 0; sub<=numsSize;sub++){
        xor = 0;
        for(int subidx = 0;subidx<sub;subidx++){
        }
    }
    return sum;
}

int main(int argc, char** argv )
{

    int nums[] = {3,4,5,6,7,8};
    int len = sizeof(nums)/sizeof(int);
    int sum = subsetXORSum(nums,len);
    printf("xor sum =%d\n",sum);
    return 0;
}

