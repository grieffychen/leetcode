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

bool canwinnim(int n)
{
    int *tbl = (int*)malloc((n+1)*sizeof(int));
    memset(tbl,0,sizeof(int)*(n+1));
    tbl[0] = 0;
    tbl[1] = 1;
    tbl[2] = 1;
    tbl[3] = 1;
    if(n>3){
        for(int i = 4;i<=n;i++){
            for(int j = 1;j<=3;j++){
                if(tbl[i-j] == 0){
                    tbl[i] = 1;
                    break;
                }
            }
        }
    } 
    bool res = (tbl[n]==1)? true:false;
    free(tbl);
    return res;
}


int main(const int argc, const char **argv)
{
    int n = 3;
    printf("result %s\n",canwinnim(n)?"win":"lose");
    return 0;
}