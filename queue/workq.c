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
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

typedef struct parm_tag{
    char *name;
    int pid;
}parm_t,*pparm_t;

typedef void (*workfunction) (parm_t arg);
typedef struct work_tag{
    parm_t arg;
    workfunction wfn;
    struct work_tag *next;
}work_t,*pwork_t;

typedef struct wlist_tag{
    pwork_t front;
    pwork_t rear;
}wlist_t,*pwlist_t;

pwork_t create_work_obj(char* wname, int pid ,workfunction fn);
void add_work_list(pwlist_t *wlist,pwork_t wobj);
pwork_t remove_work_list(pwlist_t *wlist);
bool is_work_list_empty(pwlist_t wlist);

pwork_t create_work_obj(char* wname, int pid ,workfunction fn)
{
    pwork_t obj =(pwork_t) malloc(sizeof(struct work_tag));
    obj->arg.name = wname;
    obj->arg.pid = pid;
    obj->wfn = fn;
    obj->next = NULL;
    return obj;
}
void add_work_list(pwlist_t *wlist,pwork_t wobj)
{
    if((*wlist)->front == NULL){
        (*wlist)->front = wobj;
        (*wlist)->rear = wobj;
    }else{
        (*wlist)->rear->next = wobj;
        (*wlist)->rear = wobj;
    }
}
pwork_t remove_work_list(pwlist_t *wlist)
{
    pwork_t obj = (*wlist)->front;
    if((*wlist)->front == (*wlist)->rear){
        (*wlist)->front = NULL;
    }else{
        (*wlist)->front = (*wlist)->front->next;
    }
    return obj;
}

bool is_work_list_empty(pwlist_t wlist)
{
    return wlist->front == NULL? true:false;
}

void work_fun1(parm_t arg)
{
    printf("[%s][pid=%d] start work\n",arg.name,arg.pid);
    sleep(1);
    printf("work complete\n");
}

void work_fun2(parm_t arg)
{
    printf("[%s][pid=%d] start work\n",arg.name,arg.pid);
    printf("sum : 1+1=%d\n",1+1);
    printf("work complete\n");
}

void work_fun3(parm_t arg)
{
    printf("[%s][pid=%d] start work\n",arg.name,arg.pid);
    printf("multi : 2x2=%d\n",2*2);
    printf("work complete\n");
}

int main(const int argc, const char **argv)
{
    pwlist_t pwlist = (pwlist_t) malloc(sizeof(struct wlist_tag));
    pwork_t pwobj1 = create_work_obj("work 1",1,work_fun1);
    add_work_list(&pwlist,pwobj1);

    pwork_t pwobj2 = create_work_obj("work 2",2,work_fun2);
    add_work_list(&pwlist,pwobj2);

    pwork_t pwobj3 = create_work_obj("work 3",3,work_fun3);
    add_work_list(&pwlist,pwobj3);


    pwork_t pwobj4 = create_work_obj("work 4",4,work_fun1);
    add_work_list(&pwlist,pwobj4);


    while(!is_work_list_empty(pwlist)){
        pwork_t pw = remove_work_list(&pwlist);
        pw->wfn(pw->arg);
        if(pw)
            free(pw);
    }

    if(pwlist)
        free(pwlist);
    return 0;
}