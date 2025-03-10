#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
//#include <stdio.h>
//#include <string.h>

bool backspaceCompare(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    char* s_stack = (char*)malloc(sizeof(char)*(slen+1));
    char* t_stack = (char*)malloc(sizeof(char)*(tlen+1));
    int s_top = -1;
    int t_top = -1;
    for(int i =0;i<slen;i++){
        if(s[i]=='#'){
            if(s_top!=-1)
                s_top--;
        }
        else{
            s_stack[++s_top] =s[i];
        }
    }
    for(int i =0;i<tlen;i++){
        if(t[i]=='#'){
            if(t_top!=-1)
                t_top--;
        }
        else{
            t_stack[++t_top] =t[i];
        }
    }
    memset(s,0,slen+1);
    memset(t,0,tlen+1);
    memcpy(s,s_stack,(s_top+1));
    memcpy(t,t_stack,(t_top+1));
    s[s_top+1]='\0';
    t[t_top+1]='\0';

    printf("top %d %d\n",s_top,t_top);
    
    printf("%s\n",s_stack);
    printf("%s\n",t_stack);
    printf("===result===\n");
    printf("%s\n",s);
    printf("%s\n",t);
    if(s_stack)
        free(s_stack);
    if(t_stack)
        free(t_stack);

    if(strcmp(s,t)==0)
        return true;
    else
        return false;
}

int main(const int argc, const char **argv)
{
    char str_s[] ="y#fo##f";
    char str_t[] ="y#f#o##f";
    //char str_s[] ="ab#c";
    //char str_t[] ="ad#c";
    printf("%s\n",str_s);
    printf("%s\n",str_t);
    bool res = backspaceCompare(str_s,str_t);
    printf("res =%s\n",res?"true":"false");
    return 0;
}