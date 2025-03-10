/*

318. Maximum Product of Word Lengths

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

 

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
 

Constraints:

2 <= words.length <= 1000
1 <= words[i].length <= 1000
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

int maxProduct(char** words, int wordsSize) {
    //for(int i=0;i<wordsSize;i++)
    //    printf("%d %s\n",(int)strlen(words[i]),words[i]);
    int *masktbl = (int*)malloc(sizeof(int)*wordsSize);
    for (int i =0;i<wordsSize;i++){
        int wlen = strlen(words[i]);
        int mask = 0;
        for(int j =0;j<wlen;j++){
            int v = words[i][j]-'a';
            int bit = 1<<v;
            mask=mask|bit;
        }
        masktbl[i] = mask;
    }
    //for(int i =0;i<wordsSize;i++)
    //    printf("%d \n",masktbl[i]);

    int maxlen = 0;
    for(int i =0;i<wordsSize-1;i++){
        for(int j = i+1;j<wordsSize;j++){
            if((masktbl[i]&masktbl[j]) == 0){
                int p = (int)(strlen(words[i])*strlen(words[j]));
                //printf("p=%d\n",p);
                maxlen = maxlen>p?maxlen:p;
            }
        }
    }


    if(masktbl)
        free(masktbl);
    return maxlen;   
}

int main(int argc, char** argv)
{
    char *words[] = {"abcw","baz","foo","bar","xtfn","abcdef"};
    int len = 6;
    //char *words[] = {"a","ab","abc","d","cd","bcd","abcd"};
    //int len = 7;    
    printf("len=%d\n",len);
    int ans = maxProduct(words,len);
    printf("ans=%d\n",ans);

    return 0;
}

