#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
//#include <stdio.h>
//#include <string.h>

int minLength(char * s){
    int len = (int)strlen(s)+1;
    char *stack=(char*)malloc(len*sizeof(char));
    int topidx = -1;
    int ans = len-1;
    stack[++topidx] = s[0];
    for(int i = 1;i<len-1;i++){
        printf("1 stack=%s\n",stack);
        if (s[i] == 'B'){
            if((topidx>(-1))&&(stack[topidx]=='A'))
                topidx--;
            else
                stack[++topidx] = s[i];

        }else if (s[i] == 'D'){
            if((topidx>(-1))&&(stack[topidx]=='C'))
                topidx--;
            else
                stack[++topidx] = s[i];
        }else{
            stack[++topidx] = s[i];
        }
        printf("%d top=%d\n",i,topidx);
        printf("====================\n");
    }
    printf("stack= %s\n",stack);
    if(stack)
        free(stack);
    ans = topidx+1;
    return ans;
}


int main(const int argc, const char **argv)
{
    char str[]="ACBBD";
    //char str[]="ABFCACDB";
    printf("%s\n",str);
    int minlen = minLength(str);
    printf("min len=%d\n",minlen);
    
    return 0;
}