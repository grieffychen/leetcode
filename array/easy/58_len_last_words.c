/*

58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

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


int lengthOfLastWord(char* s) {
#if 1
    int totalen = strlen(s);
    int ll = 0;
    int idx = totalen-1;
    //ignore last space
    while(s[idx]==' '){
        idx--;
    }

    while((idx>=0)&&(s[idx]!=' ')){
        idx--;
        ll++;
    }
#else
    int totallen = strlen(s);
    char *es = s+totallen-1;
    //printf("totallen=%d\n",totallen);
    int ll = 0;
    //ignore last space
    printf("%c\n",*es);
    while(*es==' '){
        es--;
    }
    printf("%c\n",*es);
    printf("-------\n");
    while(*es!=' '){
        printf("%c\n",*es);
        es--;
        ll++;
    }

#endif
    return ll;    
}

int main(int argc, char** argv)
{
    //char *s = "Hello World";
    char *s = "   fly me   to   the moon  ";
    //char *s="luffy is still joyboy";
    //char *s="a";
    int len = lengthOfLastWord(s);
    printf("%s ;last words len=%d\n",s,len);
    return 0;
}
