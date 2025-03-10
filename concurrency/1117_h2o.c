/*

1117. Building H2O

There are two kinds of threads: oxygen and hydrogen. Your goal is to group these threads to form water molecules.

There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.

In other words:

If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.
We do not have to worry about matching the threads up explicitly; the threads do not necessarily know which other threads they are paired up with. The key is that threads pass the barriers in complete sets; thus, if we examine the sequence of threads that bind and divide them into groups of three, each group should contain one oxygen and two hydrogen threads.

Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.

 

Example 1:

Input: water = "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.
Example 2:

Input: water = "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
 

Constraints:

3 * n == water.length
1 <= n <= 20
water[i] is either 'H' or 'O'.
There will be exactly 2 * n 'H' in water.
There will be exactly n 'O' in water.
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
    // User defined data may be declared here.
    int hcount;
    sem_t sem_o;
    sem_t sem_h;

} H2O;

void releaseHydrogen()
{
    printf("H");
}

void releaseOxygen()
{
    printf("O");
}

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    obj->hcount = 0;
    sem_init(&obj->sem_h ,0,0);
    sem_init(&obj->sem_o ,0,1);
    // Initialize user defined data here.
    
    return obj;
}

void hydrogen(H2O* obj) {
    
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    sem_wait(&obj->sem_h);
    obj->hcount++;
    //printf("hc=%d\n",obj->hcount);
    releaseHydrogen();
    if(obj->hcount>=2)
        sem_post(&obj->sem_o);
    else
        sem_post(&obj->sem_h);

}

void oxygen(H2O* obj) {
    
    // releaseOxygen() outputs "O". Do not change or remove this line.
    sem_wait(&obj->sem_o);
    obj->hcount = 0;
    releaseOxygen();
    sem_post(&obj->sem_h);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    obj->hcount = 0;
    sem_destroy(&obj->sem_h);
    sem_destroy(&obj->sem_o);
    if(obj)
        free(obj);
}


int main(int argc, char**argv)
{
    int n = 3;
    pthread_t thr_o[n],thr_h1[n],thr_h2[n];
    H2O *pobj = h2oCreate();

    for(int i = 0;i<n;i++){
        pthread_create(&thr_o[i],NULL,(void*)&oxygen,(void*)pobj);
        pthread_create(&thr_h1[i],NULL,(void*)&hydrogen,(void*)pobj);
        pthread_create(&thr_h2[i],NULL,(void*)&hydrogen,(void*)pobj);
    }

    for(int i = 0;i<n;i++){
        pthread_join(thr_o[i],NULL);
        pthread_join(thr_h1[i],NULL);
        pthread_join(thr_h2[i],NULL);
    }
    printf("\n");
    h2oFree(pobj);
    return 0;
}
