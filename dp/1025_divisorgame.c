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

bool divisorGame(int n)
{
    int *tbl =(int*) calloc(n+1,sizeof(int));
    for(int i=2;i<=n;i++){
        for (int j = 1;j<i;j++){
            if(i%j!=0)
                continue;
            if(tbl[i-j]==0){
                tbl[i] = 1;
                break;
            }    
        }
    }
    bool res = tbl[n] == 1? true:false;
    if(tbl)
        free(tbl);
    return res;
}


int main(const int argc, const char **argv)
{
    int n = 3;
    printf("result %s\n",divisorGame(n)?"win":"lose");
    return 0;
}