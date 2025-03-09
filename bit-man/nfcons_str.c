/*
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.
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

void printfbit(int val);
void printfbit(int val)
{
    printf("val=%d:",val);
    for(int i = 31;i>=0;i--)
        printf("%d",(val>>i)&1?1:0);
    printf("\n");
}


int countConsistentStrings(char * allowed, char ** words, int wordsSize){
    int allowlen = strlen(allowed);
    printf("allow len= %d str=%s\n",allowlen,allowed);
    int allowbitmask = 0;
    for(int i = 0;i<allowlen;i++)
        allowbitmask |= 1<<(allowed[i]-'a');
    printf("allowbitmask =%d\n",allowbitmask);
    printfbit(allowbitmask);
    int cnt = 0;
    for(int i = 0;i<wordsSize;i++){
        int swlen = strlen(words[i]);
        int con= 0;
        for(int c = 0;c<swlen;c++){
            int wbit = 1<<(words[i][c]-'a');
            printf("wbit=%d\n",wbit);
            if (wbit&allowbitmask)
                con++;
            else
                break;
        }
        printf("con=%d swlen=%d\n",con,swlen);
        if(con == swlen)
            cnt++;
        //printf("len =%d str=%s\n",swlen,words[i]);
        //printfbit(wbit);
        
    }
    
    return cnt;
}


int main(int argc, char** argv )
{
    char *allowstr = "cad";
    //char words[][] = {""};
    int wordsize = 8;
    char *words[]={"cc","acd","b","ba","bac","bad","ac","d"};
    int cnt_cons=countConsistentStrings(allowstr,words,wordsize);
    printf("asn = %d\n",cnt_cons);
    return 0;
}

