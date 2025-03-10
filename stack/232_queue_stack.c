#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
//#include <stdio.h>
//#include <string.h>

#define MAX 100
typedef struct {
    int *inbuf;
    int *outbuf;
    int intop;
    int outtop;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* pq = (MyQueue*) malloc(sizeof(MyQueue));
    pq->inbuf =(int*) malloc(sizeof(int)*MAX);
    pq->outbuf =(int*) malloc(sizeof(int)*MAX);
    pq->intop = -1;
    pq->outtop = -1;
    return pq;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inbuf[++(obj->intop)] = x;
}

int myQueuePop(MyQueue* obj) {
#if 0
    while(obj->outtop!=-1){
        obj->inbuf[++(obj->intop)] = obj->outbuf[(obj->outtop)--];
    }     
    while(obj->intop!=-1){
        obj->outbuf[++(obj->outtop)] = obj->inbuf[(obj->intop)--];
    }
    return obj->outbuf[(obj->outtop)--];
#else
    int frontval;
    while(obj->intop>-1){
        obj->outbuf[++(obj->outtop)] = obj->inbuf[(obj->intop)--];
    }
    frontval = obj->outbuf[obj->outtop];
    obj->outtop--;
    while(obj->outtop>-1){
        obj->inbuf[++(obj->intop)] = obj->outbuf[(obj->outtop)--]; 
    }
    return frontval;
#endif    
}

int myQueuePeek(MyQueue* obj) {
    int frontval;
    while(obj->intop>-1){
        obj->outbuf[++(obj->outtop)] = obj->inbuf[(obj->intop)--];
    }
    frontval = obj->outbuf[obj->outtop];
    //obj->outtop--;
    while(obj->outtop>-1){
        obj->inbuf[++(obj->intop)] = obj->outbuf[(obj->outtop)--]; 
    }
    return frontval;
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->intop == -1)?true:false;
}

void myQueueFree(MyQueue* obj) {
    if(obj->outbuf)
        free(obj->outbuf);
    if(obj->inbuf)
        free(obj->inbuf);
    free(obj);
}

void dispalymyQueue(MyQueue*obj ){
while(obj->intop>-1){
        obj->outbuf[++(obj->outtop)] = obj->inbuf[(obj->intop)--];
    }
    for(int i =obj->outtop;i>-1;i--){
        printf(" %d -->",obj->outbuf[i]);
    }
    printf("rear\n");
    //obj->outtop--;
    while(obj->outtop>-1){
        obj->inbuf[++(obj->intop)] = obj->outbuf[(obj->outtop)--]; 
    }
}

int main(const int argc, const char **argv)
{
    MyQueue *qobj = myQueueCreate();
    myQueuePush(qobj,1);
    myQueuePush(qobj,2);
    myQueuePush(qobj,3);
    myQueuePush(qobj,4);
    dispalymyQueue(qobj);
    printf("pop %d \n",myQueuePop(qobj));
    printf("pop %d \n",myQueuePop(qobj));
    myQueuePush(qobj,5);
    myQueuePush(qobj,6);
    printf("peek =%d\n",myQueuePeek(qobj));
    dispalymyQueue(qobj);
    myQueueFree(qobj);
    return 0;
}