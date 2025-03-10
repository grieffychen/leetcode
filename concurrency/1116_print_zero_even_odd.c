/*

1116. Print Zero Even Odd

You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
void zero(printNumber) Calls printNumber to output one zero.
void even(printNumber) Calls printNumber to output one even number.
void odd(printNumber) Calls printNumber to output one odd number.
 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"
 

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

typedef struct {
    int n;
    int idx;
    sem_t sem_zero;
    sem_t sem_even;
    sem_t sem_odd;
} ZeroEvenOdd;

void printNumber(int x)
{
    printf("%d",x);
}


ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    obj->idx = 0;
    sem_init(&obj->sem_zero,0,1);
    sem_init(&obj->sem_even,0,0);
    sem_init(&obj->sem_odd,0,0);
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    for(int i =0;i<obj->n;i++){
        sem_wait(&obj->sem_zero);
        printNumber(0);
        if(i%2){
            sem_post(&obj->sem_even);
        }else{
            sem_post(&obj->sem_odd);
        }

    }

}

void even(ZeroEvenOdd* obj) {

    for(int i =2;i<=obj->n;i=i+2){
        sem_wait(&obj->sem_even);
        printNumber(i);
        sem_post(&obj->sem_zero);
    }
}

void odd(ZeroEvenOdd* obj) {
    
    for(int i =1;i<=obj->n;i=i+2){
        sem_wait(&obj->sem_odd);
        printNumber(i);
        sem_post(&obj->sem_zero);   
    }
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    sem_destroy(&obj->sem_zero);
    sem_destroy(&obj->sem_even);
    sem_destroy(&obj->sem_odd);
    if(obj)
        free(obj);
}

void *zero_fun(void* arg)
{
    zero((ZeroEvenOdd*) arg);
}

void *even_fun(void* arg)
{
    even((ZeroEvenOdd*) arg);
}

void *odd_fun(void* arg)
{
    odd((ZeroEvenOdd*) arg);
}



int main(int argc, char**argv)
{
    pthread_t thr_zero,thr_even,thr_odd;
    int n = 5;
    ZeroEvenOdd *obj = zeroEvenOddCreate(5);
#if 0    
    pthread_create(&thr_zero,NULL,zero_fun,(void*)obj);
    pthread_create(&thr_even,NULL,even_fun,(void*)obj);
    pthread_create(&thr_odd,NULL,odd_fun,(void*)obj);
#else    
    pthread_create(&thr_zero,NULL,(void*)&zero,(void*)obj);
    pthread_create(&thr_even,NULL,(void*)&even,(void*)obj);
    pthread_create(&thr_odd,NULL,(void*)&odd,(void*)obj);
#endif
    pthread_join(thr_zero,NULL);
    pthread_join(thr_even,NULL);
    pthread_join(thr_odd,NULL);

    printf("\n");
    zeroEvenOddFree(obj);
    return 0;
}
