/*
2114. Maximum Number of Words Found in Sentences

A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

You are given an array of strings sentences, where each sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single sentence.

 

Example 1:

Input: sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
Output: 6
Explanation: 
- The first sentence, "alice and bob love leetcode", has 5 words in total.
- The second sentence, "i think so too", has 4 words in total.
- The third sentence, "this is great thanks very much", has 6 words in total.
Thus, the maximum number of words in a single sentence comes from the third sentence, which has 6 words.
Example 2:

Input: sentences = ["please wait", "continue to fight", "continue to win"]
Output: 3
Explanation: It is possible that multiple sentences contain the same number of words. 
In this example, the second and third sentences (underlined) have the same number of words.
 

Constraints:

1 <= sentences.length <= 100
1 <= sentences[i].length <= 100
sentences[i] consists only of lowercase English letters and ' ' only.
sentences[i] does not have leading or trailing spaces.
All the words in sentences[i] are separated by a single space.

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
#define bforce  1

#if bforce
int mostWordsFound(char ** sentences, int sentencesSize){
    
    int max = 0;
    for(int i=0;i<sentencesSize;i++){
        int len = strlen(sentences[i]);
        int space = 0;
        for(int j=0;j<len;j++){
            if(sentences[i][j] ==' '){
                space++;
            }
        }
        if(max<space)
            max = space;
    }
    return max+1;
}
#endif


int main(int argc, char** argv)
{
    #define sentsize    3
    char *sentences[sentsize] = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    //int len = sentsize;
    for(int i = 0;i<sentsize;i++){
        printf("%s\n",sentences[i]);
    }
    int max = mostWordsFound(sentences,sentsize);
    printf("max words=%d\n",max);

    return 0;
}
