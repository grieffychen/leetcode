/*
2942. Find Words Containing Character

You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.

 

Example 1:

Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
Example 2:

Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.
Example 3:

Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.
 

Constraints:

1 <= words.length <= 50
1 <= words[i].length <= 50
x is a lowercase English letter.
words[i] consists only of lowercase English letters.


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



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int *ansbuf = (int*) malloc(wordsSize*sizeof(int));
    int cnt = 0;
    char dest[2] = {0};
    dest[0] = x;
    dest[1] = '\0';
    for(int i = 0;i<wordsSize;i++){
        if(strstr(words[i],dest) !=NULL){
            ansbuf[cnt] = i;
            cnt++;
        }
    }
    *returnSize = cnt;
    return ansbuf;
}


int main(int argc, char** argv)
{
    char *testwords[]={"abc","bcd","aaaa","cbc"};
    int retlen = 0;
    int testlen = sizeof(testwords)/sizeof(char*);
    printf("test len=%d, unit %d \n",testlen,sizeof(char*));
    int *ans = findWordsContaining(testwords,testlen,'a',&retlen);

    for(int i = 0;i<retlen;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");

    return 0;
}
