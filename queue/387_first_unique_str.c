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

#if 1
int firstUniqChar(char* s) {
    int map[26]={0};
    int len = strlen(s);
    for(int i = 0;i<len;i++){
        map[s[i]-'a']++;
    }
    //int idx = 0;
    for(int idx =0;idx<len;idx++){
        if(map[s[idx]-'a'] ==1)
        return idx;
    }
    return -1;

}
#else
typedef struct qnode_tag{
    char s;
    struct qnode_tag *next;
}qnode_t,*pqnode_t;

void dbg_display(pqnode_t pqhead);
void release_q(pqnode_t *pqhead);


void dbg_display(pqnode_t pqhead)
{
    pqnode_t cur = pqhead;
    while(cur){
        printf("%c->",cur->s);
        cur=cur->next;
    }
    printf("NULL\n");
}
void release_q(pqnode_t *pqhead){
    pqnode_t cur = *pqhead;
    while(cur){
        pqnode_t temp =cur;
        cur=cur->next;
        free(temp);
    }
    *pqhead = NULL;

}

int firstUniqChar(char* s) {
    pqnode_t p_queue = NULL;
    int len =strlen(s);
    printf("strlen=%d\n",len);

    for(int i = 0;i<len;i++){
        pqnode_t pn =(pqnode_t) malloc(sizeof(struct qnode_tag));
        pn->s = s[i];
        pn->next = NULL;
        if (p_queue ==NULL){
            p_queue = pn;
        }else{
            pqnode_t cur = p_queue;
            while(cur->next)
                cur=cur->next;
            cur->next = pn;
        }
    }
    dbg_display(p_queue);
    int idx =0;
    int cnt = 0;
    for(int i = 0;i<len;i++){
        //bool isunique = true;
        pqnode_t cur = p_queue;
        pqnode_t pre = NULL;
        cnt = 0;
        p_queue = cur;
        //remove duplicate  
        while(cur){
            if(cur->s == s[i] &&(pre == NULL)){ //first node
                cnt++;
                pqnode_t temp = cur;
                cur=cur->next;
                p_queue =cur;
                free(temp);
            }else if(cur->s == s[i] &&(cur->next == NULL)){ // last node
                cnt++;
                pqnode_t temp = cur;
                pre->next =NULL;
                cur=cur->next;
                free(temp);
            }else if(cur->s == s[i]){
                cnt++;
                pqnode_t temp = cur;
                pre->next =cur->next;
                cur=cur->next;
                free(temp);                
            }else{
                pre=cur;
                cur=cur->next;
            }
        }
        dbg_display(p_queue);
        printf("cnt =%d\n",cnt);
        if(cnt == 1){
            idx =i;
            break;
        }
    }
    if(p_queue == NULL && (cnt !=1))
        idx = -1;

    release_q(&p_queue);
    return idx;
}
#endif

int main(const int argc, const char **argv)
{
    //char *str = "loveleetcode";
    //char *str ="aabb";
    //char *str ="z";
    char *str = "dddccdbba" ;
    printf("%s\n",str);
    int index = firstUniqChar(str);
    printf("%d\n",index);

    return 0;
}