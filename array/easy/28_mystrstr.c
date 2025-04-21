/*
28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.


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

int strStr(char* haystack, char* needle) {
    int lh = strlen(haystack);
    int ln = strlen(needle);

    for(int i = 0;i<=lh-ln;i++){
        int s = 0;
        while((s<ln)&&haystack[i+s]==needle[s]){
            s++;
        }
        if(s==ln)
            return i;
    }
    return -1;
}

int main(int argc, char** argv)
{
    //char haystack[] = "sadbutsad";
    //char needle[] = "sad";
    char haystack[] = "leetcode";
    char needle[] = "leeto";

    printf("%s %s \n",haystack,needle);
    int ans = strStr(haystack,needle);
    printf("%d\n",ans);
    return 0;
}
