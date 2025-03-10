/*

1115. Print FooBar Alternately

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

 

Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
 

Constraints:

1 <= n <= 1000



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

void printFoo();
void printBar();


typedef struct {
    int n;
    sem_t sem_foo;
    sem_t sem_bar;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    sem_init(&obj->sem_foo,0,1);
    sem_init(&obj->sem_bar,0,0);
    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        // printFoo() outputs "foo". Do not change or remove this line.
        sem_wait(&obj->sem_foo);
        printFoo();
        sem_post(&obj->sem_bar);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        
        // printBar() outputs "bar". Do not change or remove this line.
        sem_wait(&obj->sem_bar);
        printBar();
        sem_post(&obj->sem_foo);
    }
}

void fooBarFree(FooBar* obj) {
    sem_destroy(&obj->sem_foo);
    sem_destroy(&obj->sem_bar);
    if(obj)
        free(obj);
}

void printFoo()
{
    printf("Foo\n");
}
void printBar()
{
    printf("Bar\n");
}


int main(int argc, char**argv)
{
    pthread_t thr_foo;
    pthread_t thr_bar;
    int n = 5;
    FooBar *pobj = fooBarCreate(n);
    pthread_create(&thr_foo,NULL,foo,(void*)pobj);
    pthread_create(&thr_bar,NULL,bar,(void*)pobj);

    pthread_join(thr_foo,NULL);
    pthread_join(thr_bar,NULL);

    if(pobj)
        fooBarFree(pobj);
    return 0;
}
