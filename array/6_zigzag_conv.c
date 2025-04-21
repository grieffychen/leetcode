/*

6. Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

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

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if(len<numRows)
        return s;
    if(numRows ==1)
        return s;
    char **zig = (char**)malloc(sizeof(char*)*numRows);
    for(int i =0;i<numRows;i++)
        zig[i] = (char*) calloc(len,sizeof(char));

    int row = 0;
    int dir = -1;
    for(int i = 0;i<len;i++){
        strncat(zig[row],&s[i],1);
        if(row%(numRows-1) == 0)
            dir=dir*(-1);        
        row+=dir;
    }
    //for(int i = 0;i<numRows;i++)
    //    printf("%s\n",zig[i]);
    memset(s,'\0',len);
    for(int i =0;i<numRows;i++)
        strcat(s,zig[i]);

    for(int i =0;i<numRows;i++)
        free(zig[i]);
    free(zig);
    return s;
}

int main(int argc, char** argv)
{
    //char str[]="PAYPALISHIRING";
    //int row=3;
    //char str[]="PAYPALISHIRING";
    //int row = 4;
    char str[]="ABCDEFGHIJKLMN";
    int row = 4;
    char *ans = convert(str,row);
    if(ans)
        printf("%s\n",ans);
    return 0;
}
