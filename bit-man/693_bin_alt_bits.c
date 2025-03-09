/*
693. Binary Number with Alternating Bits
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
 

Constraints:

1 <= n <= 231 - 1
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


bool hasAlternatingBits1(int n){
    int val1 = (n+(n>>1))+1;
    int val2 = (n+(n>>1));
    printf("%d\n",val1&val2);
    return val1&val2 ? false:true;
}

bool hasAlternatingBits2(int n){
    int val1 = n^(n>>2);
    return (val1 & (val1-1)) ? false:true;
}

int main(int argc, char** argv)
{
    int num = atoi(argv[1]);

    //bool res = hasAlternatingBits1(num);
    bool res = hasAlternatingBits2(num);
    printf("result=%s \n",res?"true":"false");
    return 0;
}

