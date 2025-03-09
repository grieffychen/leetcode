/*
1763. Longest Nice Substring
A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.

 

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
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

char * longestNiceSubstring(char * s)
{
    int len = (int)strlen(s);
    int low_case = 0;
    int up_case = 0;
    int subidx = -1;
    int maxlen = 0;
    for (int i = 0 ;i <len;i++){
        low_case = 0;
        up_case = 0;
        for (int j = i;j<len;j++){
            if((s[j]>='A') && s[j]<='Z'){
                up_case = up_case |(1<<(s[j]-'A'-1));
            }

            if((s[j]>='a') && s[j]<='z'){
                low_case = low_case |(1<<(s[j]-'a'-1));
            }
            if((low_case^up_case) == 0)
            {
                if(maxlen < j-i+1){
                    maxlen = j-i+1;
                    subidx = i;
                }
            }

        }
    }
    if((maxlen == 0)||(subidx ==-1)){
        return "";
    }
    char *res = (char*)calloc(maxlen+1,sizeof(char));
    memcpy(res,&s[subidx],maxlen); 
    return res;
}


int main(int argc, char** argv)
{
    ////int num = atoi(argv[1]);
    char *input_str = argv[1];
    char *res = longestNiceSubstring(input_str);
    printf("%s\n",res);
    return 0;
}

