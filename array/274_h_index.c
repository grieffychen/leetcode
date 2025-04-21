/*

274. H-Index


Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000




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

int cmp(const void *a,const void *b)
{
    return (*((int*)b)) - (*((int*)a));
}

int hIndex(int* citations, int citationsSize) {
    
    qsort(citations,citationsSize,sizeof(int),cmp);
    //for(int i =0;i<citationsSize;i++)
    //    printf("%d ",citations[i]);
    printf("\n");

    for(int i =0;i<citationsSize;i++){
        if(citations[i]<=i)
            return i;
    }
    
    return citationsSize;
}

int main(int argc, char** argv)
{   
    int citations[] = {3,0,6,1,5};
    //int citations[] = {1,3,1};
    int len = sizeof(citations)/sizeof(citations[0]);

    int hidx = hIndex(citations,len);
    printf("h index=%d\n",hidx);

    return 0;
}
