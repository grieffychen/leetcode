/*
 *622. Design Circular Queue

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. 

 

Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
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
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) ;
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
int myCircularQueueFront(MyCircularQueue* obj);
int myCircularQueueRear(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* obj = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
	obj->qsize = k+1;
	obj->qbuf = (int*) malloc(sizeof(int)*obj->qsize);
	obj->front= 0;
	obj->rear = 0;
	return obj ;  
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//if((obj->rear+1)%obj->qsize == obj->front)
	if(myCircularQueueIsFull(obj))	
		return false;
	//obj->rear = (obj->rear++)%obj->qsize;
	//printf("enque\n");
	obj->qbuf[obj->rear] = value;
	obj->rear = (obj->rear+1)%obj->qsize;
	//printf("enq f=%d r =%d\n",obj->front,obj->rear);
	//obj->qbuf[obj->rear] = value;
	//obj->qbuf[(++obj->rear)%obj->qsize];
	//(obj->rear++)%obj->qsize;
	return true;    
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    	//if(obj->front == obj->rear)
	if(myCircularQueueIsEmpty(obj))	
		return false;
	//obj->qbuf[obj->front];
	//(obj->front++)%obj->qsize;
	obj->front=(obj->front+1)%obj->qsize;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	//if((obj->rear+1)%obj->qsize==obj->front)
	//	return -1;
	//printf("front idx=%d\n",obj->front);
	//if(obj->front == -1)
	//	return -1;
	//else if(obj->rear ==obj->front)
	//	return -1;
	//else
	if(myCircularQueueIsEmpty(obj))	
		return -1;
	return obj->qbuf[obj->front];    
}

int myCircularQueueRear(MyCircularQueue* obj) {
	//printf("rear idx =%d \n",obj->rear);
	//if(obj->front == -1)
	//	return -1;
	//else if(obj->rear ==obj->front)
	//	return -1;
	//else
	if(myCircularQueueIsEmpty(obj))	
		return -1;
	
	return obj->qbuf[(obj->rear+obj->qsize-1)%obj->qsize];    
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	//if(obj->front == -1)
	//	return true;
	return (obj->front==obj->rear?true:false);    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return ((obj->rear+1)%obj->qsize == obj->front ?true:false);    
}

void myCircularQueueFree(MyCircularQueue* obj) {
	if(obj->qbuf)
		free(obj->qbuf);
	if(obj)
		free(obj);
}

int main(int argc, char**argv)
{
/*
 *MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
 
 */     
	MyCircularQueue* pqobj = myCircularQueueCreate(3);
	if(!myCircularQueueEnQueue(pqobj,1)){
		printf("enqueue fail\n");
	}
	if(!myCircularQueueEnQueue(pqobj,2)){
		printf("enqueue fail\n");
	}
	if(!myCircularQueueEnQueue(pqobj,3)){
		printf("enqueue fail\n");
	}
	if(!myCircularQueueEnQueue(pqobj,4)){
		printf("enqueue fail\n");
	}
	printf("rear=%d\n",myCircularQueueRear(pqobj));
	printf("Is full=%s\n",myCircularQueueIsFull(pqobj)?"True":"False");
	if(!myCircularQueueDeQueue(pqobj)){
		printf("dequeue fail\n");
	}
	if(!myCircularQueueEnQueue(pqobj,4)){
		printf("enqueue fail\n");
	}

	printf("rear=%d\n",myCircularQueueRear(pqobj));
        return 0;

	myCircularQueueFree( pqobj);
}
