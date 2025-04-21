/*


380. Insert Delete GetRandom O(1)


Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

 

Example 1:

Input
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
Output
[null, true, false, true, 2, true, false, 2]

Explanation
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
randomizedSet.insert(2); // 2 was already in the set, so return false.
randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
 

Constraints:

-231 <= val <= 231 - 1
At most 2 * 105 calls will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>			// File Control Definitions.
#include <termios.h>		// POSIX Terminal Control Definitions.
#include <unistd.h>			// UNIX Standard Definitions.
#include <errno.h>			// ERROR Number Definitions.
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
    int *arr;
    int count;
    int capcity;
} RandomizedSet;


RandomizedSet* randomizedSetCreate() {
    RandomizedSet *obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    
    obj->capcity =1;
    obj->arr = (int*)malloc(sizeof(int)*obj->capcity);
    //printf("1\n");
    obj->count =0;
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if(obj->count == obj->capcity){
        obj->capcity*=2;
        obj->arr =(int*)realloc(obj->arr,sizeof(int)*obj->capcity);
    }
    for(int i =0;i<obj->count;i++){
        if(obj->arr[i] == val){
            return false;
        }
    }
    obj->arr[obj->count] = val;
    obj->count++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    
    for(int i =0;i<obj->count;i++){
        if(obj->arr[i] == val){
            obj->arr[i] = obj->arr[obj->count-1];
            obj->count--;
            return true;
        }
    }
    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    if(obj->count ==0)
        return INT_MIN;
    int idx = rand()%obj->count;
    return obj->arr[idx];
}

void randomizedSetFree(RandomizedSet* obj) {
    if(obj->arr)
        free(obj->arr);
    if(obj)
        free(obj);
}



int main(int argc, char** argv)
{   
    RandomizedSet* randobj= randomizedSetCreate();
    bool res ;
    res = randomizedSetInsert(randobj,1);
    printf("%s\n",res?"true":"false");
    res = randomizedSetRemove(randobj,2); 
    printf("%s\n",res?"true":"false");
    res = randomizedSetInsert(randobj,2);
    printf("%s\n",res?"true":"false");
    int r = randomizedSetGetRandom(randobj);
    printf("rand val=%d\n",r);
    res = randomizedSetRemove(randobj,1); 
    printf("%s\n",res?"true":"false");    
    res = randomizedSetInsert(randobj,2);
    printf("%s\n",res?"true":"false");
    r = randomizedSetGetRandom(randobj);
    printf("rand val=%d\n",r);
    randomizedSetFree(randobj);    
    return 0;
}
