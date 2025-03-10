/*
201. Bitwise AND of Numbers Range

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1

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



int rangeBitwiseAnd(int left, int right) {
    //int ans = right;
#if 0    
    while(right>left){
        right = right&(right-1);
        //right--;
    }
    return right;
#else    
    int ans = right;
    
    while(right>left){
        ans = ans&(right-1);
        right--;
    }
    return ans;
#endif
}


int main(int argc, char** argv)
{
    //int left = 1;
    //int right= 2147483647;
    int left = 5;
    int right= 7;

    int ans = rangeBitwiseAnd(left,right);
    printf("ans=%d\n",ans);

    return 0;
}

