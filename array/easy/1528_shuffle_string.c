/*
1528. Shuffle String
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
 

Constraints:

s.length == indices.length == n
1 <= n <= 100
s consists of only lowercase English letters.
0 <= indices[i] < n
All values of indices are unique.

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

char * restoreString(char * s, int* indices, int indicesSize){
    char *ret = (char*)malloc((indicesSize+1)*sizeof(char));
    for(int i =0;i<indicesSize;i++){

        //ret[i] = s[indices[i]];
        ret[indices[i]] = s[i];
    }
    ret[indicesSize]='\0';
    return ret;
}

int main(int argc, char** argv)
{
    char s[] = "codeleet";
    int indices[] = {4,5,6,7,0,2,1,3};
    int charlen = sizeof(s)/sizeof(char);
    int idxlen = sizeof(indices)/sizeof(int);
    printf("len %d %d\n",charlen,idxlen);
    printf("%s\n",s);

    char *res=restoreString(s,indices,idxlen);
    if(res){
        printf("%s\n",res);
        free(res);
    }

    return 0;
}
