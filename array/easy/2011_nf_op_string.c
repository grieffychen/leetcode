/*
2011. Final Value of Variable After Performing Operations
There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

 

Example 1:

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
Example 2:

Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
Example 3:

Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
 

Constraints:

1 <= operations.length <= 100
operations[i] will be either "++X", "X++", "--X", or "X--".

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

int finalValueAfterOperations(char ** operations, int operationsSize){
    int cnt =0;
    for(int i =0;i<operationsSize;i++){
        if(strcmp(operations[i],"X++")==0)
            cnt++;
        else if(strcmp(operations[i],"++X")==0)
            cnt++;
        else if(strcmp(operations[i],"X--")==0)
            cnt--;
        else if(strcmp(operations[i],"--X")==0)
            cnt--;
    }
    return cnt;
}
int main(int argc, char** argv)
{
    char *operations[] = {"X++","++X","--X","X--"};
    //printf("%d %d\n",sizeof(operations),sizeof("X++"));
    int opsize = sizeof(operations)/sizeof("X++")/2;
    //printf("operation size=%d\n",opsize);
    for(int i = 0;i<opsize;i++)
        printf("%s\n",operations[i]);
    int final = finalValueAfterOperations(operations,opsize);
    printf("final value=%d\n",final);
    return 0;
}
