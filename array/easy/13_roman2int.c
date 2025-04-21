/*

13. Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].

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


int R2I(char c)
{
    if(c =='I')
        return 1;
    else if(c=='V')
        return 5;
    else if(c=='X')
        return 10;
    else if(c=='L')
        return 50;
    else if(c=='C')
        return 100;
    else if(c=='D')
        return 500;
    else //M
        return 1000;
}

int r2sign(char cur,char next)
{
    if(((cur=='I')&& (next=='V'))|| 
        ((cur=='I')&&(next=='X'))||
        ((cur=='X')&&(next=='L'))||
        ((cur=='X')&&(next=='C'))||
        ((cur=='C')&&(next=='D'))||
        ((cur=='C')&&(next=='M'))){
            return -1;
    }else
        return 1;
}


int romanToInt(char* s) {

    int num = 0;
    int len = strlen(s);
    //printf("%d\n",len);
    for(int i=0;i<len-1;i++){
        int curval = R2I(s[i]);
        int sign = r2sign(s[i],s[i+1]);
        num+=sign*curval;
    }
    num+=R2I(s[len-1]);
    return num;
}

int main(int argc, char** argv)
{
    //char *str ="III";
    //char *str ="LVIII";
    char *str ="MCMXCIV";
    
    int val = romanToInt(str);
    printf("%s=%d\n",str,val);
    return 0;
}
