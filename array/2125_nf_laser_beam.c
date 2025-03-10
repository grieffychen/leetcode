/*

2125. Number of Laser Beams in a Bank

Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.

Example 1:


Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.
Example 2:


Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.




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



int numberOfBeams(char** bank, int bankSize) {
    int *cellbuf = (int*)calloc(bankSize,sizeof(int));
    for(int i = 0;i<bankSize;i++){
        int cellcnt = 0;
        int len =strlen(bank[i]);
        //printf("len=%d %s\n",len,bank[i]);
        for(int j =0;j<len;j++){
            cellcnt+=bank[i][j]-'0';
            //printf("%d cnt=%d\n",i,cellcnt);
        }
        cellbuf[i] = cellcnt;
    }
    //for(int i=0;i<bankSize;i++){
    //    printf("%d ",cellbuf[i]);
    //}
    //printf("\n");
    int start = 0;
    int end = 1;
    int total = 0;
    while((start<bankSize )&&(end < bankSize)){
        if(cellbuf[end] == 0){
            end++;
        }else if(cellbuf[start]==0){
            start++;
        }
        else if (start == end){
            end++;
        }
        else if((cellbuf[end]!=0) &&(cellbuf[start]!=0)){
            total += cellbuf[start]*cellbuf[end];
            start++;
            end++;
        }
        //printf("start =%d end=%d\n",start,end);
    }
    return total;  
}

int main(int argc, char** argv)
{
    char* bank[] = {"011001","000000","010100","001000"};
    int banklen = sizeof(bank)/(sizeof(bank[0])*sizeof(char));
    printf("bank size =%d\n",banklen);
    
    int nf_beams = numberOfBeams(bank,banklen);
    printf("total nf of beams=%d\n",nf_beams);
    return 0;
}
