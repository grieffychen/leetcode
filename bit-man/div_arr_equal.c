
/*
You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.

 

Example 1:

Input: nums = [3,2,3,2,2,2]
Output: true
Explanation: 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
Example 2:

Input: nums = [1,2,3,4]
Output: false
Explanation: 
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
 

Constraints:

nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500

bool divideArray(int* nums, int numsSize){
    int pairs = numsSize/2;
    int res=0;
    int h[501]={0};
    for(int i=0;i<numsSize;i++)
        h[nums[i]]++;
    for(int i=0;i<numsSize;i++)
    {
        if(h[nums[i]]%2!=0)
            return false;
        res=res+h[nums[i]]/2;
        h[nums[i]]=0;
    }
    return res==pairs;
}

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





bool divideArray(int* nums, int numsSize){
#if 0    
    int val = nums[0];

    for (int i = 1;i<numsSize;i++){
        val = val^nums[i];
    }

    return val?false:true;
#endif
    int nummap[501] = {0};
    for (int i = 0;i<numsSize;i++){
        nummap[nums[i]]++;
    }
    int pair = 0 ;
    for(int j = 0;j<501;j++){
        if(nummap[j]%2!=0)
            return false;
        pair += nummap[j]/2;
    }
    return pair==numsSize/2;

}



int main(int argc, char** argv )
{
    int nums[] = {3,2,3,2,2,2};
    int len = sizeof(nums)/sizeof(int);
    bool res = divideArray(nums,len);
    printf("the array %s into pair\n",res?"can":"can't");

    return 0;
}

