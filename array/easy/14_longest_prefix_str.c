/*

14. Longest Common Prefix


Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

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


char* longestCommonPrefix(char** strs, int strsSize) {
    int min =INT_MAX;
    char* mstr  = NULL;
    for(int i = 0;i<strsSize;i++){
        int len = strlen(strs[i]);
        if(len<INT_MAX){
            min = len;
            mstr = strs[i];
        }
    }
    char *cmstr = (char*)calloc(min+1,sizeof(char));
    for(int i = 0;i<min;i++){

        bool match = true;
        for(int j = 0;j<strsSize;j++){
            if(mstr[i] != strs[j][i]){
                match = false;
                break;
            }    
        }
        if(match){
            cmstr[i] = mstr[i];
        }else{
            break;
        }
    }
    return cmstr;
}

int main(int argc, char** argv)
{
    //char *str[]  = {"flower","flow","flight"};
    char *str[] = {"dog","racecar","car"};
    int len = sizeof(str)/sizeof(str[0]);
    printf("len=%d\n",len);
    for(int i = 0 ;i < len;i++){
        printf("%s\n",str[i]);
    }
    
    char *comstr = longestCommonPrefix(str,len);
    if(comstr){
        printf("%s\n",comstr);
        free(comstr);
    }
    return 0;
}
