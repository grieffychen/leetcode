/*
641. Design Circular Deque

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>                      // File Control Definitions.
#include <termios.h>            // POSIX Terminal Control Definitions.
#include <unistd.h>                     // UNIX Standard Definitions.
#include <errno.h>                      // ERROR Number Definitions.
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


typedef struct {
    int *qbuf;
    int qsize;
    int front;
    int rear;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k);
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value);
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value);
bool myCircularDequeDeleteFront(MyCircularDeque* obj);
bool myCircularDequeDeleteLast(MyCircularDeque* obj);
int myCircularDequeGetFront(MyCircularDeque* obj);
int myCircularDequeGetRear(MyCircularDeque* obj);
bool myCircularDequeIsEmpty(MyCircularDeque* obj) ;
bool myCircularDequeIsFull(MyCircularDeque* obj) ;
void myCircularDequeFree(MyCircularDeque* obj) ;



MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque * pcdq = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    pcdq->qsize = k+1;
    pcdq->qbuf=(int*) malloc(sizeof(int)*pcdq->qsize);
    pcdq->front=pcdq->rear=(k+1)/2;
    return pcdq;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;
    //printf("insert front=%d\n",obj->front);
    obj->front=(obj->front+obj->qsize-1)%obj->qsize;
    obj->qbuf[obj->front] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj))
        return false;
    //printf("insert rear=%d\n",obj->rear);        
    obj->qbuf[obj->rear] = value;
    obj->rear = (obj->rear+1)%obj->qsize;    
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return false;
    obj->front = (obj->front+1)%obj->qsize;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return false;
    obj->rear = (obj->rear+obj->qsize-1)%obj->qsize;    
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return -1;
    return obj->qbuf[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj))
        return -1;    
    return obj->qbuf[(obj->rear+obj->qsize-1)%obj->qsize];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->front == obj->rear ? true:false);
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {

    return (obj->rear+obj->qsize+1)%(obj->qsize) == obj->front?true:false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if(obj->qbuf)
        free(obj->qbuf);
    if(obj)
        free(obj);
}

#define dbg 0

int main(int argc, char**argv)
{
    /*
Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4    
    */
    MyCircularDeque *pdcq = myCircularDequeCreate(3);
    if(!myCircularDequeInsertLast(pdcq,1)){
        printf("insert last fail\n");
    }
    if(!myCircularDequeInsertLast(pdcq,2)){
       printf("insert last fail\n");
    }
    if(!myCircularDequeInsertFront(pdcq,3)){
        printf("insert front fail\n");
    }
#if dbg
    for(int i =0;i<4;i++)

#endif
    if(!myCircularDequeInsertFront(pdcq,4)){
        printf("insert front fail\n");
    }
    printf("rear =%d\n",myCircularDequeGetRear(pdcq));
    printf("Is full=%s\n",myCircularDequeIsFull(pdcq)?"True":"False");
    if(!myCircularDequeDeleteLast(pdcq)){
        printf("delete last fail\n");
    }
    if(!myCircularDequeInsertFront(pdcq,4)){
        printf("insert front fail\n");
    }
    printf("front =%d\n",myCircularDequeGetFront(pdcq));

    myCircularDequeFree(pdcq);
    return 0;
}
