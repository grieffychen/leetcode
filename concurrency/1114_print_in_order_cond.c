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
    pthread_cond_t cond2;
    pthread_cond_t cond3;
    pthread_mutex_t lock;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    pthread_cond_init(&obj->cond2,NULL);
    pthread_cond_init(&obj->cond3,NULL);
    pthread_mutex_init(&obj->lock,NULL);
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    //sem_wait(&obj->sem1);
    printFirst();
    pthread_cond_signal(&obj->cond2);

}

void second(Foo* obj) {
    
    // printSecond() outputs "second". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    pthread_cond_wait(&obj->cond2,&obj->lock);
    printSecond();
    pthread_cond_signal(&obj->cond3);
    pthread_mutex_unlock(&obj->lock);
}

void third(Foo* obj) {
    
    // printThird() outputs "third". Do not change or remove this line.
    pthread_mutex_lock(&obj->lock);
    pthread_cond_wait(&obj->cond3,&obj->lock);
    printThird();
    pthread_mutex_unlock(&obj->lock);
    
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    //sem_destroy(&obj->sem1);
    pthread_cond_destroy(&obj->cond2);
    pthread_cond_destroy(&obj->cond3);
    pthread_mutex_destroy(&obj->lock);
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
