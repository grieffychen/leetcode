/*

371. Sum of Two Integers

Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000


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

int getSum(int a, int b) {
#if 1
    while(b){
        unsigned int carry = a&b;
        a=a^b;
        b=carry<<1;
    }
    return a;

#else    
    int bitcnt = 0;
    int sum = 0;
    int carry = 0;
    int ans =0;
    while(a||b||carry){
        int bita = a&1;
        int bitb = b&1;
        sum = bita^bitb^carry;
        if((bita&&bitb&&carry)||(bita&&bitb&&!carry) ||(bita&&!bitb&&carry)||(!bita&&bitb&&carry))
            carry = 1;
        else
            carry = 0;

        ans = ans |(sum<<bitcnt);
        printf("bcnt=%d carry=%d %d\n",bitcnt,carry,ans);
        a=a>>1;
        b=b>>1;
        bitcnt++;
        if(bitcnt>31)
            break;
    }
    return ans;
#endif    
}


int main(int argc, char** argv)
{
    //int a = 1;
    //int b = 2;
    int a = -12;
    int b =-18;
    int ans = getSum(a,b);
    printf("ans=%d\n",ans);

    return 0;
}

