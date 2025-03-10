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

bool isSubsequence(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    int subcnt = 0;
    int startidx = 0;
    printf("%d %d \n",slen,tlen);
    for(int i =0;i<slen;i++){
        int j = startidx;
        printf("strat idx =%d\n",startidx);
        bool found = false;
        while(t[j]!='\0'){
            printf("%c %c \n",s[i],t[j]);
            if(s[i]==t[j]){
                found = true;
                break;
            }
            j++;
        }
        if(found){
            startidx = j+1;
            subcnt++;
            printf("found startidx =%d\n",startidx);
        }else{
            return false;
        }
    }
    if(subcnt == slen)
        return true;
    else
        return false;

}

int main(const int argc, const char **argv)
{
    //char sstr[] = "abc";
    //char tstr[] = "ahbgdc";
    char sstr[] = "acb";
    char tstr[] = "ahbgdc";    
    printf("result=%s\n",isSubsequence(sstr,tstr)?"true":"false");

    return 0;
}