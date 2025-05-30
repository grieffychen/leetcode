/*
1769. Minimum Number of Operations to Move All Balls to Each Box

You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 

Constraints:

n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.



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
int* minOperations(char* boxes, int* returnSize) 
{
    int len = strlen(boxes);
    *returnSize = len;
    printf("len =%d\n",len);
    int *ansarr = (int*) calloc(len,sizeof(int));
    for(int i = 0;i<len;i++){
        int op = 0;
        for(int j =0;j<len;j++){
            if(boxes[j] =='1'){
                op+=abs(j-i);
            }
        }
        ansarr[i] = op;
    }
    return ansarr;
}

int main(int argc, char** argv)
{
    char* boxes = "001011";
    int len = 0;
    int *ans = minOperations(boxes,&len);

    for(int i = 0;i<len;i++)
        printf("%d ",ans[i]);
    printf("\n");

    return 0;
}
