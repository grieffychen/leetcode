/*

264. Ugly Number II

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690

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



int nthUglyNumber(int n) {
    int *uglybuf = (int*)malloc(sizeof(int)*n);
    uglybuf[0] = 1;
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    for(int i =1;i<n;i++){
        int next2 = uglybuf[i2]*2;
        int next3 = uglybuf[i3]*3;
        int next5 = uglybuf[i5]*5;

        int min_next = 0;
        if(next2<next3){
            if(next2<next5){
                min_next = next2;
            }else{
                min_next = next5;
            }
        }else{
            if(next3<next5){
                min_next = next3;
            }else{
                min_next = next5;
            }
        }
        uglybuf[i] = min_next;
        printf("i=%d val=%d [%d %d %d] [%d %d %d]\n",i,min_next,i2,i3,i5,next2,next3,next5);
        if(min_next == next2)
            i2++;
        if(min_next == next3)
            i3++;
        if(min_next == next5)
            i5++;

    }
    int ans = uglybuf[n-1];
    if(uglybuf)
        free(uglybuf);
    return ans;
}

int main(int argc, char** argv)
{
    int n =10;
    int ans =nthUglyNumber(n);
    printf("ans=%d\n",ans);
    return 0;
}
