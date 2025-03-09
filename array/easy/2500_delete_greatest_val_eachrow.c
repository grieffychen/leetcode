/*
You are given an m x n matrix grid consisting of positive integers.

Perform the following operation until grid becomes empty:

Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
Add the maximum of deleted elements to the answer.
Note that the number of columns decreases by one after each operation.

Return the answer after performing the operations described above.

 

Example 1:


Input: grid = [[1,2,4],[3,3,1]]
Output: 8
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can remove any of them). We add 4 to the answer.
- In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
- In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
The final answer = 4 + 3 + 1 = 8.
Example 2:


Input: grid = [[10]]
Output: 10
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 10 from the first row. We add 10 to the answer.
The final answer = 10.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 100

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

#define bf  1

//int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
int deleteGreatestValue(int gridSize) {
#if bf 
    int sum = 0;
    //int *maxbuf = (int*) calloc(gridSize,sizeof(int));
    int grid[2][3] = {{1,2,4},{3,3,1}};
    int gridcol[2] = {3,3};    
    //int n = gridColSize[0];
    int n = 3;
    int m = gridSize;
    printf("m =%d n=%d\n",m,n);
    for(int cnt = 0;cnt<n;cnt++){
        printf("cnt =%d\n",cnt);
        int rowmax = 0;
        for (int i = 0;i<m;i++){
            int colmaxidx = 0;
            int colmax = 0;
            printf("i=%d\n",i);
            for (int j =0;j<n;j++){
                printf("i=%d j=%d\n",i,j);
                if (grid[i][j]>colmax){
                    colmax = grid[i][j];
                    colmaxidx = j;
                }
            }
            grid[i][colmaxidx]=0;
            if(colmax>rowmax)
                rowmax = colmax;
        }
        sum+=rowmax;
    }
    return sum;
#endif
}

int main(int argc, char** argv)
{
    int grid[2][3] = {{1,2,4},{3,3,1}};
    int gridcol[2] = {3,3};
    //int sum = deleteGreatestValue(grid,2,gridcol);
    int sum = deleteGreatestValue(2);
    printf("sum =%d\n",sum);
    return 0;
}
