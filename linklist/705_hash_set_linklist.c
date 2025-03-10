/*

705. Design HashSet


Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define HSIZE   10000
typedef struct node_tag{
    int key;
    struct node_tag *next;
}node_t , *pnode_t;

typedef struct {
    pnode_t *bucket;
    int bucketSize;   
} MyHashSet;

pnode_t create_node(int key)
{
    pnode_t node = (pnode_t) malloc(sizeof(struct node_tag));
    node->key = key;
    node->next = NULL;
    return node;
}

int hash(int key)
{
    return key%HSIZE;
}

MyHashSet* myHashSetCreate() {
    MyHashSet *hashobj = (MyHashSet*) malloc(sizeof( MyHashSet));
    hashobj->bucketSize = HSIZE;
    hashobj->bucket = (pnode_t*) calloc(hashobj->bucketSize,sizeof(pnode_t));
    return hashobj;
}

void myHashSetAdd(MyHashSet* obj, int key) {

    int hashval = hash(key);
    pnode_t curhashhead = obj->bucket[hashval];
    while(curhashhead){
        if(curhashhead->key == key){
            return;
        }
        curhashhead = curhashhead->next;
    }
    pnode_t node = create_node(key);
    node->next = obj->bucket[hashval];
    obj->bucket[hashval] = node;

}

void myHashSetRemove(MyHashSet* obj, int key) {
    int hashval = hash(key);
    pnode_t curhashhead = obj->bucket[hashval];
    pnode_t pre = NULL;

    while(curhashhead){
        if(curhashhead->key == key){
            break;
        }
        pre = curhashhead;
        curhashhead = curhashhead->next;
    }
    if(pre){
        pre->next = curhashhead->next;
        //free(curhashhead);
    }else{
        obj->bucket[hashval] = curhashhead->next;
        //free(curhashhead);
    }
    free(curhashhead);
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int hashval = hash(key);
    pnode_t curhashhead = obj->bucket[hashval];

    while(curhashhead){
        if(curhashhead->key == key){
            return true;
        }
        curhashhead = curhashhead->next;
    }
    return false;

}

void myHashSetFree(MyHashSet* obj) {
    for(int i = 0 ;i< obj->bucketSize;i++){
        pnode_t curhashhead = obj->bucket[i];
        //pnode_t cur;
        while(curhashhead){
            pnode_t cur = curhashhead;
            curhashhead = curhashhead->next;
            free(cur);
        }
    }
    free(obj->bucket);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/

void printlist(struct ListNode *head)
{

}

void printlistpoint(struct ListNode *head)
{

}

void freelist(struct ListNode *head)
{

}

int main(int argc, char** argv)
{

    return 0;
}
