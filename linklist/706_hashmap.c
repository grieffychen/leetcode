/*
706. Design HashMap
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

Constraints:

0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.

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
#define HASHSIZE    10000

typedef struct node_tag{
    int key;
    int val;
    struct node_tag *next;
}node_t,*pnode_t;

typedef struct {
    pnode_t *bucket;
    int bucket_len;
} MyHashMap;

int hash(int key)
{
    return key%HASHSIZE;
}

pnode_t create_node(int key,int val)
{
    pnode_t node = (pnode_t)malloc(sizeof(struct node_tag));
    node->key = key;
    node->val = val;
    node->next = NULL;
    return node;
}

MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap*) malloc(sizeof(MyHashMap));
    obj->bucket_len = HASHSIZE;
    obj->bucket = (pnode_t *) calloc(obj->bucket_len,sizeof(pnode_t));
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int hashval = hash(key);
    pnode_t curhead = obj->bucket[hashval];
    while(curhead){
        if(curhead->key == key){
            //printf("the key exists\n");
            curhead->val = value;
            return;
        }
        curhead = curhead->next;
    }
    pnode_t node = create_node(key,value);
    node->next = obj->bucket[hashval];
    obj->bucket[hashval] = node;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int hashval = hash(key);
    pnode_t curhead = obj->bucket[hashval];
    while(curhead){
        if(curhead->key == key){
            return curhead->val;
        }
        curhead = curhead->next;
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int hashval = hash(key);
    pnode_t curhead = obj->bucket[hashval];
    pnode_t pre = NULL;

    while(curhead){
        if(curhead->key == key){
            if(pre){
                pre->next = curhead->next;
            }else{
                obj->bucket[hashval] = curhead->next;
            }
            free(curhead);
            break;
        }
        pre = curhead;
        curhead = curhead->next;
    }  

}

void myHashMapFree(MyHashMap* obj) {
    for(int i = 0;i<obj->bucket_len;i++){
        int hashval = hash(i);
        pnode_t curhead = obj->bucket[hashval];
        while(curhead){
            pnode_t temp = curhead;
            curhead = curhead->next;
            free(temp);
        } 
    }
    free(obj->bucket);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/

int main(int argc, char** argv)
{

    return 0;
}
