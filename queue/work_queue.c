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
    int wid;
    char *wname;
}parm_t,*pparm_t;

typedef void(*workfun)(parm_t arg);
typedef struct workobj_tag{
    parm_t arg;
    //void (*workfun)(pparm_t parm) ;
    workfun wfn;
    struct workobj_tag *next;
}workobj_t,*pworkob_t;


pworkob_t create_workobj(int work_id,char *workname,workfun fn);
void add_work_queue(pworkob_t *wqfront,pworkob_t wobj);
pworkob_t remove_work_queue(pworkob_t *wqfront);

void work_obj_function(parm_t arg)
{
    printf("work id =%d work name=%s\n",arg.wid,arg.wname);
}

pworkob_t create_workobj(int work_id,char *workname,workfun fn)
{
    pworkob_t wobj = (pworkob_t) malloc(sizeof(struct workobj_tag));
    parm_t arg;
    arg.wid = work_id;
    arg.wname = workname;
    wobj->arg = arg;
    wobj->wfn = fn;
    wobj->next = NULL;
}

void add_work_queue(pworkob_t *wqfront,pworkob_t wobj)
{
    if(*wqfront == NULL){
        *wqfront = wobj;
        return;
    }else{
        pworkob_t cur = *wqfront;
        while(cur->next){
            cur=cur->next;
        }
        cur->next = wobj;
        return ;
    }
}

pworkob_t remove_work_queue(pworkob_t *wqfront)
{
    pworkob_t front = *wqfront;
    *wqfront = front->next;
    return front;
}

int main(const int argc, const char **argv)
{
    pworkob_t pwork_queue = NULL;
    pworkob_t job1 = create_workobj(1,"job1",work_obj_function);
    pworkob_t job2 = create_workobj(2,"job2",work_obj_function);
    pworkob_t job3 = create_workobj(3,"job3",work_obj_function);
    pworkob_t job4 = create_workobj(4,"job4",work_obj_function);
    pworkob_t job5 = create_workobj(5,"job5",work_obj_function);
    add_work_queue(&pwork_queue,job1);
    add_work_queue(&pwork_queue,job4);
    add_work_queue(&pwork_queue,job5);
    add_work_queue(&pwork_queue,job2);
    add_work_queue(&pwork_queue,job3);    

    while(pwork_queue){
        pworkob_t work = remove_work_queue(&pwork_queue);
        work->wfn(work->arg);
        if(work)
            free(work);
    }

    return 0;
}