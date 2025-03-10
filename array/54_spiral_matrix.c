/*
54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

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

#if 1
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int total = matrixSize*matrixColSize[0];
    int *ansarr = (int*)malloc(sizeof(int)*(total));
    *returnSize = total;
    char **map = (char**) malloc(sizeof(char*)*matrixSize);
    for(int i = 0;i<matrixSize;i++)
        map[i] = (char*) calloc(matrixColSize[0],sizeof(char));

    int di = 0;
    int dc[4] = {1,0,-1,0};
    int dr[4] = {0,1,0,-1};
    int col = 0;
    int row = 0;

    for(int idx =0;idx<total;idx++){
        ansarr[idx] = matrix[row][col];
        map[row][col] = 1;

        int next_col = col +dc[di];
        int next_row = row +dr[di];

        if((next_col>=0&&next_col<matrixColSize[0])&&
            (next_row>=0&&next_row<matrixSize)&&
            !map[next_row][next_col]){
                row = next_row;
                col = next_col;
        }else{
            di=(di+1)%4;
            row +=dr[di];
            col +=dc[di];
        }
    }

    for(int i =0;i<matrixSize;i++)
        free(map[i]);
    free(map);
    return ansarr;    
}
#else
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int total = matrixSize*matrixColSize[0];
    int *ansarr = (int*)malloc(sizeof(int)*(total));
    *returnSize = total;
    int start_x = 0;
    int start_y = 0;
    int end_x = matrixColSize[0]-1;
    int end_y = matrixSize -1;
    int idx = 0;

    while((idx<total)&&(start_x<=end_x)&&(start_y<=end_y)){
        // -->
        for(int i =start_x;i<=end_x&&idx<total;i++){
            ansarr[idx] = matrix[start_y][i];
            //printf("%d [%d %d](%d)\n",idx, start_y,i,matrix[start_y][i]);
            idx++;
        }
        start_y++;
        //  |
        //  V
        for(int i = start_y;i<=end_y&&idx<total;i++){
            ansarr[idx] = matrix[i][end_x];
            //printf("%d [%d %d](%d)\n",idx, i,end_x,matrix[i][end_x]);
            idx++;
        }
        end_x--;
        // <--
        if(start_y<=end_y){
            for(int i = end_x;i>=start_x&&idx<total;i--){
                ansarr[idx] = matrix[end_y][i];
                //printf("%d [%d %d](%d)\n",idx, end_y,i,matrix[end_y][i]);
                idx++;
            }
            end_y--;
        }
        // A
        // |
        if(start_x<=end_y){
            for(int i = end_y;i>=start_y&&idx<total;i--){
                ansarr[idx] = matrix[i][start_x];
                //printf("%d [%d %d](%d)\n",idx, i,start_x,matrix[i][start_x]);
                idx++;
            }
            start_x++;
        }
    }
    return ansarr;    
}
#endif

int main(int argc, char** argv)
{
    int m[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int **mat =(int**) malloc(sizeof(int*)*3);
    int *mcol = (int*)malloc(sizeof(int)*3);
    for(int i = 0;i<3;i++){
        mcol[i] = 4;
        mat[i] = (int*) malloc(sizeof(int)*4);
    }
    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            mat[i][j] =m[i][j];
            printf("%3d ",mat[i][j]);
        }
        printf("\n");
    }

    int retlen = 0;
    int *arr =  spiralOrder(mat,3,mcol,&retlen);

    for(int i = 0;i<retlen;i++)
        printf("%d ",arr[i]);
    printf("\n");

    if(arr)
        free(arr);
    return 0;
}
