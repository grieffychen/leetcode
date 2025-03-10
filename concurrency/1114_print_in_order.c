/*

1114. Print in Order

Suppose we have a class:

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

 

Example 1:

Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
Example 2:

Input: nums = [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 

Constraints:

nums is a permutation of [1, 2, 3].


 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>                      // File Control Definitions.
#include <termios.h>            // POSIX Terminal Control Definitions.
#include <unistd.h>                     // UNIX Standard Definitions.                  
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
#include <pthread.h>
#include <semaphore.h>

void printFirst();
void printSecond();
void printThird();


typedef struct {
    // User defined data may be declared here.
    sem_t sem1;
    sem_t sem2;
    sem_t sem3;
    
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    //sem_init(&obj->sem1,0,1);
    sem_init(&obj->sem2,0,0);
    sem_init(&obj->sem3,0,0);
    // Initialize user defined data here.
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    //sem_wait(&obj->sem1);
    printFirst();
    sem_post(&obj->sem2);
}

void second(Foo* obj) {
    
    // printSecond() outputs "second". Do not change or remove this line.
    sem_wait(&obj->sem2);
    printSecond();
    sem_post(&obj->sem3);
}

void third(Foo* obj) {
    
    // printThird() outputs "third". Do not change or remove this line.
    sem_wait(&obj->sem3);
    printThird();
    
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    //sem_destroy(&obj->sem1);
    sem_destroy(&obj->sem2);
    sem_destroy(&obj->sem3);
    if(obj)
        free(obj);
}

void printFirst()
{
    printf("First\n");
}
void printSecond()
{
    printf("Second\n");
}
void printThird()
{
    printf("Third\n");
}

int main(int argc, char**argv)
{
    Foo *pobj = fooCreate();
    pthread_t thra,thrb,thrc;
    pthread_create(&thra,NULL,first,(void*)pobj);
    pthread_create(&thrb,NULL,second,(void*)pobj);
    pthread_create(&thrc,NULL,third,(void*)pobj);

    pthread_join(thra,NULL);
    pthread_join(thrb,NULL);
    pthread_join(thrc,NULL);
    printf("thread complete\n");
    fooFree(pobj);
    return 0;
}
