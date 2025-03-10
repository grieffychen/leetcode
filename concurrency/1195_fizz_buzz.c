/*

1195. Fizz Buzz Multithreaded

You have the four functions:

printFizz that prints the word "fizz" to the console,
printBuzz that prints the word "buzz" to the console,
printFizzBuzz that prints the word "fizzbuzz" to the console, and
printNumber that prints a given integer to the console.
You are given an instance of the class FizzBuzz that has four functions: fizz, buzz, fizzbuzz and number. The same instance of FizzBuzz will be passed to four different threads:

Thread A: calls fizz() that should output the word "fizz".
Thread B: calls buzz() that should output the word "buzz".
Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
Thread D: calls number() that should only output the integers.
Modify the given class to output the series [1, 2, "fizz", 4, "buzz", ...] where the ith token (1-indexed) of the series is:

"fizzbuzz" if i is divisible by 3 and 5,
"fizz" if i is divisible by 3 and not 5,
"buzz" if i is divisible by 5 and not 3, or
i if i is not divisible by 3 or 5.
Implement the FizzBuzz class:

FizzBuzz(int n) Initializes the object with the number n that represents the length of the sequence that should be printed.
void fizz(printFizz) Calls printFizz to output "fizz".
void buzz(printBuzz) Calls printBuzz to output "buzz".
void fizzbuzz(printFizzBuzz) Calls printFizzBuzz to output "fizzbuzz".
void number(printNumber) Calls printnumber to output the numbers.
 

Example 1:

Input: n = 15
Output: [1,2,"fizz",4,"buzz","fizz",7,8,"fizz","buzz",11,"fizz",13,14,"fizzbuzz"]
Example 2:

Input: n = 5
Output: [1,2,"fizz",4,"buzz"]
 

Constraints:

1 <= n <= 50
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
    //int idx;
    bool isend;
    //pthread_mutex_t lock;
    sem_t sem_fizz;
    sem_t sem_buzz;
    sem_t sem_fizzbuzz;
    sem_t sem_num; 
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    //obj->idx = 1;
    obj->isend = false;
    //pthread_mutex_init(&obj->lock,NULL);
    sem_init(&obj->sem_buzz,0,0);
    sem_init(&obj->sem_fizz,0,0);
    sem_init(&obj->sem_fizzbuzz,0,0);
    sem_init(&obj->sem_num,0,1);
    return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    while(true){
        sem_wait(&obj->sem_fizz);
        if(!obj->isend){
            printf("fizz\n");
            sem_post(&obj->sem_num);
        }else{
            break;
        }
    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    while(true){
        sem_wait(&obj->sem_buzz);
        if(!obj->isend){
            printf("buzz\n");
            sem_post(&obj->sem_num);
        }else{
            break;
        }
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
    while(true){
        sem_wait(&obj->sem_fizzbuzz);
        if(!obj->isend){
            printf("fizzbuzz\n");
            sem_post(&obj->sem_num);
        }else{
            break;
        }
    }    
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    
    for(int i = 1;i<=obj->n;i++){
        sem_wait(&obj->sem_num);
        if((i%3==0)&&(i%5==0)){
            sem_post(&obj->sem_fizzbuzz);
        }else if((i%3==0)&&(i%5!=0)){
            sem_post(&obj->sem_fizz);
        }else if((i%3!=0)&&(i%5==0)){
            sem_post(&obj->sem_buzz);
        }else{
            printf("%d\n",i);
            sem_post(&obj->sem_num);
        }
    }
    sem_wait(&obj->sem_num);
    obj->isend = true;
    sem_post(&obj->sem_fizzbuzz);
    sem_post(&obj->sem_fizz);
    sem_post(&obj->sem_buzz);
}

void fizzBuzzFree(FizzBuzz* obj) {
    sem_destroy(&obj->sem_fizz);
    sem_destroy(&obj->sem_buzz);
    sem_destroy(&obj->sem_fizzbuzz);
    if(obj)
        free(obj);
}


int main(int argc, char**argv)
{
    pthread_t thr_fizz;
    pthread_t thr_buzz;
    pthread_t thr_fizzbuzz;
    pthread_t thr_num;
    int n = 16;
    FizzBuzz* pobj=fizzBuzzCreate(n);
    pthread_create(&thr_fizz,NULL,(void*)&fizz,(void*)pobj);
    pthread_create(&thr_buzz,NULL,(void*)&buzz,(void*)pobj);
    pthread_create(&thr_fizzbuzz,NULL,(void*)&fizzbuzz,(void*)pobj);
    pthread_create(&thr_num,NULL,(void*)&number,(void*)pobj);


    pthread_join(thr_fizz,NULL);
    pthread_join(thr_fizzbuzz,NULL);
    pthread_join(thr_fizzbuzz,NULL);
    pthread_join(thr_num,NULL);

    printf("Test Complete\n");
    fizzBuzzFree(pobj);
    return 0;
}
