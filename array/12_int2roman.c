/*

12. Integer to Roman

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"
        MMMDCCXLIXI
Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"
        MCMXLIV
Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999



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


char* intToRoman(int num) {
    char *str = (char*)malloc(sizeof(char)*16);
    int idx = 0;
    while(num>=1000){
        str[idx++] = 'M';
        num-=1000;
    }
    if(num>=900){
        str[idx++]='C';
        str[idx++]='M';
        num-=900;
    }
    if(num>=500){
        str[idx++] = 'D';
        num-=500;
    }
    if(num>=400){
        str[idx++]='C';
        str[idx++]='D';
        num-=400;
    }    
    while(num>=100){
        str[idx++]='C';
        num-=100;
    }
    //printf("%s\n",str);
    if(num>=90){
        str[idx++]='X';
        str[idx++]='C';
        num-=90;
    }    
    if(num>=50){
        str[idx++] = 'L';
        num-=50;
    }
    if(num>=40){
        str[idx++]='X';
        str[idx++]='L';
        num-=40;
    }     
    while(num>=10){
        str[idx++]='X';
        num-=10;
    }
    if(num>=9){
        str[idx++]='I';
        str[idx++]='X';
        num-=9;
    }
    //printf    
    if(num>=5){
        str[idx++] = 'V';
        num-=5;
    }
    if(num>=4){
        str[idx++]='I';
        str[idx++]='V';
        num-=9;
    }    
    while(num>0){
        str[idx++]='I';
        num-=1;
    }
    str[idx] = '\0';
    return str;
}

int main(int argc, char** argv)
{   
    //int num =3749;
    //int num =58;
    int num =1994;

    char *str = intToRoman(num);

    if(str){
        printf("%d =%s\n",num,str);
        free(str);
    }
    return 0;

}
