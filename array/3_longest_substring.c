/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

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


#if 1
int lengthOfLongestSubstring(char * s){
    int len = sizeof(s)/sizeof(char);
    int ridx = 0;
    int lidx = 0;
    int *count = (int*) malloc(256* sizeof(int));
    memset(count,0, 256*sizeof(int));
    int max = 0;
    while(s[ridx]!='\0'){
        if(count[s[ridx]] == 0){
            count[s[ridx]]++;
            ridx++;
        }else{
            count[s[lidx]] = 0;
            lidx++;
        }
        if (max<(ridx-lidx))
            max = ridx- lidx;    
    }
    free(count);
    return max;
}
#else
int lengthOfLongestSubstring(char * s){
    int len = sizeof(s)/sizeof(char);
    int ridx = 0;
    int lidx = 0;
    int *count = (int*) malloc(256* sizeof(int));
    memset(count,0, 256*sizeof(int));
    int max = 0;
    while(ridx < len){
        if(count[s[ridx]] == 0){
            count[s[ridx]]++;
            ridx++;
        }else{
            count[s[lidx]] = 0;
            lidx++;
        }
        if (max<(ridx-lidx))
            max = ridx- lidx;    
    }
    free(count);
    return max;
}
#endif


int main(int argc, char** argv)
{
    char *lstring = "abcabcbb";

    int max = lengthOfLongestSubstring(lstring);
    printf("max = %d\n",max);

    return 0;
}
