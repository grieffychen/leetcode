/*
29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0

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


int divide(int dividend, int divisor) {
    int sign = ((dividend>=0)^(divisor>=0)) ?-1:1; 
    printf("sign=%d\n",sign);
    //if((dividend == INT_MAX)&&(divisor ==1))
    //    return INT_MAX;
    if((dividend == INT_MIN)&&(divisor ==1))
        return INT_MIN;
    if((dividend == INT_MIN)&&(divisor ==-1))
        return INT_MAX;
    //if((dividend == INT_MAX)&&(divisor ==-1))
    //    return INT_MIN;
    //long long dividendL = abs(dividend);
    //long long diviosrL = abs(divisor);
    long long int dividendL = dividend;
    long long int diviosrL = divisor;
    dividendL = dividendL<0?-dividendL:dividendL;
    diviosrL = diviosrL<0?-diviosrL:diviosrL;
    //dividendL = -dividendL;
    //dividendL = abs(dividendL);
    //diviosrL = abs(diviosrL);        
    long long int quotient = 0;
    long long int sum = 0;
    printf("abs dividendL =%d %d divisorL=%lld\n",dividendL,abs(dividendL),diviosrL);
    for (int i = 31;i>=0;i--){
        if((sum+(diviosrL<<i)) <=dividendL){
            sum+=(diviosrL<<i);
            quotient += (1<<i);
        }
    }
    
    //quotient=sign*quotient;
    if(sign*quotient>INT_MAX)
        return INT_MAX;

    return sign*quotient;
}

int main(int argc, char** argv)
{
    //int dividend = 10;
    //int divisor = -3;
    int dividend = -2147483648;
    //int test =        4294967296;
    //int dividend = 10;
    int divisor = 2;
    printf("int max =%d int min =%d\n",INT_MAX,INT_MIN);
    int q = divide(dividend,divisor);
    printf("quotient=%d\n",q);

    return 0;
}

