#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int front;
    int rear;
    int *qbuf;
    int tf;
    int tr;
    int *tempbuf;
} MyStack;


MyStack* myStackCreate() {
    MyStack *pst = (MyStack*) malloc(sizeof(MyStack));
    pst->front = -1;
    pst->rear = -1;
    pst->tf=-1;
    pst->tr=-1;
    pst->qbuf = (int*) malloc(sizeof(int)*100);
    pst->tempbuf = (int*) malloc(sizeof(int)*100);
    return pst;
}

void myStackPush(MyStack* obj, int x) {
    if(obj->front == -1){
        obj->front = 0;
        obj->rear = 0;
        obj->qbuf[obj->rear] = x;
    }else{
        obj->tf = 0;
        obj->tr = -1;
        while(obj->front<=obj->rear){
            obj->tempbuf[++(obj->tr)] = obj->qbuf[obj->front++];
        }
        obj->rear = -1;
        obj->front = 0;
        obj->qbuf[++(obj->rear)] = x;
        while(obj->tf<=obj->tr){
            obj->qbuf[++(obj->rear)] = obj->tempbuf[(obj->tf)++];
        }
    }
}

int myStackPop(MyStack* obj) {
    return obj->qbuf[(obj->front)++];
}

int myStackTop(MyStack* obj) {
    return obj->qbuf[(obj->front)];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->front==-1)
        return true;
    else
        return (obj->front>obj->rear? true:false);
}

void myStackFree(MyStack* obj) {
    if(obj->qbuf)
        free(obj->qbuf);
    if(obj->tempbuf)
        free(obj->tempbuf);
    free(obj);
}



int main(const int argc, const char **argv)
{
    MyStack* pqst = myStackCreate();
    myStackPush(pqst,1);
    myStackPush(pqst,2);
    printf("top=%d\n",myStackTop(pqst));
    printf("pop=%d\n",myStackPop(pqst));
    printf("is empty=%s\n",myStackEmpty(pqst)?"true":"false");
    return 0;
}