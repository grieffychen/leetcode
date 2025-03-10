/*

2545. Sort the Students by Their Kth Score

There is a class with m students and n exams. You are given a 0-indexed m x n integer matrix score, where each row represents one student and score[i][j] denotes the score the ith student got in the jth exam. The matrix score contains distinct integers only.

You are also given an integer k. Sort the students (i.e., the rows of the matrix) by their scores in the kth (0-indexed) exam from the highest to the lowest.

Return the matrix after sorting it.

 

Example 1:


Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
Output: [[7,5,11,2],[10,6,9,1],[4,8,3,15]]
Explanation: In the above diagram, S denotes the student, while E denotes the exam.
- The student with index 1 scored 11 in exam 2, which is the highest score, so they got first place.
- The student with index 0 scored 9 in exam 2, which is the second highest score, so they got second place.
- The student with index 2 scored 3 in exam 2, which is the lowest score, so they got third place.
Example 2:


Input: score = [[3,4],[5,6]], k = 0
Output: [[5,6],[3,4]]
Explanation: In the above diagram, S denotes the student, while E denotes the exam.
- The student with index 1 scored 5 in exam 0, which is the highest score, so they got first place.
- The student with index 0 scored 3 in exam 0, which is the lowest score, so they got second place.
 

Constraints:

m == score.length
n == score[i].length
1 <= m, n <= 250
1 <= score[i][j] <= 105
score consists of distinct integers.
0 <= k < n



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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** sortTheStudents(int** score, int scoreSize, int* scoreColSize, int k, int* returnSize, int** returnColumnSizes) {
    for(int i = 0;i<scoreSize;i++){
        for(int j = 0;j<scoreColSize[0];j++)
            printf("%3d ",score[i][j]);
        printf("\n");
    }
    *returnSize = scoreSize;
    printf("===sort %d ===\n",k);

    //int **ansarr = (int**) malloc(sizeof(int*)*scoreSize);
    for(int si = 0;si<scoreSize;si++){
        int max=INT_MIN;
        int maxidx = si;
        for(int sj = si;sj<scoreSize;sj++){
            if(score[sj][k]>max){
                max = score[sj][k];
                maxidx = sj;
            }    
        }
        (*returnColumnSizes)[si] = scoreColSize[0];
        for (int j = 0;j<scoreColSize[0];j++){
            int tmp = score[si][j];
            score[si][j] = score[maxidx][j];
            score[maxidx][j] = tmp;
        }
    }
    return score;
}

int main(int argc, char** argv)
{

    //Input: score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
    int sc[3][4] = {{10,6,9,1},{7,5,11,2},{4,8,3,15}};
    int k = 2;
    //int score1[] = {10,6,9,1};
    //int score2[] = {7,5,11,2};
    //int score3[] = {4,8,3,15};
    int scorelen =3;
    int scoreCollen = sizeof(sc[0])/sizeof(int);
    int **score =(int**)malloc(sizeof(int*)*scorelen) ;
    int *scColsize = (int*) malloc(sizeof(int)*scorelen);
    //score[0] = &score1[0];
    //score[1] = &score1
    for(int i = 0;i<scorelen;i++){
        scColsize[i] = scoreCollen;
        score[i] = &sc[i][0];
    }
    printf("score len =%d col len=%d\n",scorelen,scoreCollen);
    int rtSize = 0;
    int *rtColSzie = (int*) malloc(scorelen*sizeof(int));
    int **ans = sortTheStudents(score,scorelen,scColsize,2,&rtSize,&rtColSzie);


    for(int i = 0;i<rtSize;i++){
        for(int j = 0;j<rtColSzie[0];j++)
            printf("%3d ",score[i][j]);
        printf("\n");
    }


    if(scColsize)
        free(scColsize);
    if(score)
        free(score);
    return 0;
}
