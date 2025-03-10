/*
1828. Queries on Number of Points Inside a Circle


You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on a 2D plane. Multiple points can have the same coordinates.

You are also given an array queries where queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.

For each query queries[j], compute the number of points inside the jth circle. Points on the border of the circle are considered inside.

Return an array answer, where answer[j] is the answer to the jth query.


Input: points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
Output: [3,2,2]
Explanation: The points and circles are shown above.
queries[0] is the green circle, queries[1] is the red circle, and queries[2] is the blue circle.


Input: points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries = [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
Output: [2,3,2,4]
Explanation: The points and circles are shown above.
queries[0] is green, queries[1] is red, queries[2] is blue, and queries[3] is purple.




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
int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int *ansarr = (int*) malloc(queriesSize*sizeof(int));
    
    for(int qi = 0; qi<queriesSize;qi++){
        int cnt = 0;
        int rsquare = queries[qi][2]*queries[qi][2];
        for(int pi = 0;pi<pointsSize;pi++){
            int dx = points[pi][0] - queries[qi][0];
            int dy = points[pi][1] - queries[qi][1];
            if((dx*dx+dy*dy) <= rsquare)
                cnt++;
        }
        ansarr[qi] = cnt;
    }

    return NULL;
}

int main(int argc, char** argv)
{
    int points[4][2]={{1,3},{3,3},{5,3},{2,2}};
    int ptCol[4] = {2,2,2,2};
    int queries[3][3] = {{2,3,1},{4,3,1},{1,1,2}};
    int quCol[3] = {3,3,3};

    int anslen = 0;
    int *ans = countPoints(points,4,ptCol,queries,3,quCol,&anslen);

    for(int i = 0;i<anslen;i++)
        printf("%d ",ans[i]);
    printf("\n");
    free(ans);
    return 0;
}
