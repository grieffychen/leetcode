/*
2326. Spiral Matrix IV

You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000


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

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

#if 0
enum{
    rstep = 1,
    dstep = -1,
    lstep = -1,
    ustep = 1,
};
#endif
enum{
    right,
    left,
    up,
    down,
};
enum{
    row,
    col,
    total,
};

struct ListNode* create_node(int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void append_list(struct ListNode** head,int val)
{
    struct ListNode* node = create_node(val);
    if(*head ==NULL){
        *head = node;
        return;
    }
    struct ListNode* cur = *head;
    while(cur->next){
        cur=cur->next;
    }
    cur->next=node;
}

void pirnt_list(struct ListNode* head)
{
    struct ListNode* cur = head;
    while(cur){
        printf("%d-> ",cur->val);
        cur=cur->next;
    }
    printf("NULL\n");
}

void free_list(struct ListNode* head)
{
    while(head){
        struct ListNode* temp = head;
        head=head->next;
        free(temp);
    }
}

int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) 
{
    int **ansmat = (int**)malloc(sizeof(int*)*m);
    char **map =(char**)malloc(sizeof(char*)*m);
    for(int i =0;i<m;i++)
        ansmat[i] = (int*)malloc(sizeof(int)*n);
    *returnSize = m;
    *returnColumnSizes =(int*)malloc(sizeof(int)*m);
    for(int i =0;i<m;i++){
        (*returnColumnSizes)[i]=n;
        //memset(map[i],0,sizeof(char)*n);
        map[i] = (char*)calloc(n,sizeof(char));
        for(int j = 0;j<n;j++){
            ansmat[i][j] = -1;
            //map[i][j] = 0;
        }
    }
    printf("initial value\n");
    for(int i =0;i<m;i++){
        for(int j =0;j<n;j++){
            printf("%2d,%2d  ",ansmat[i][j],map[i][j]);
        }
        printf("\n");
    }


    int dc[4] ={1,0,-1,0};
    int dr[4] ={0,1,0,-1};
    //int direction = right;
    int col = 0;
    int row = 0;
    int di =0;
    int idx = 0;
    //int turnpoint[total] = {0,n-1};
    while(head){
        ansmat[row][col] = head->val;
        map[row][col] = 1;
        
        int newrow = row+dr[di];
        int newcol = col+dc[di];
        idx++;
        if( (newrow>=0&&newrow<m) &&
            (newcol>=0&&newcol<n)&&
            !map[newrow][newcol]){
            
            row=newrow;
            col=newcol;
        }else{
            di = (di+1)%4;
            row +=dr[di];
            col +=dc[di];
        }
        head=head->next;
    }


    return ansmat;   
}

int main(int argc, char** argv)
{
    int headval[] = {3,0,2,6,8,1,7,9,4,2,5,5,0};
    struct ListNode* head = NULL;
    
    for(int i = 0;i<sizeof(headval)/sizeof(int);i++){
        append_list(&head,headval[i]);
    }
    pirnt_list(head);
    int retm = 0;
    int *retn = NULL;
    int **matrix = spiralMatrix(3,5,head,&retm,&retn);

    printf("==result==\n");    
    free_list(head);

    for(int i =0;i<retm;i++){
        for(int j =0;j<retn[0];j++)
            printf("%2d ",matrix[i][j]);
        printf("\n");
    }

    if(retn)
        free(retn);
    for(int i =0;i<retm;i++)
        free(matrix[i]);
    if(matrix)
        free(matrix);
    return 0;
}
