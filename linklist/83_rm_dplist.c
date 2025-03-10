/*
83. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

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

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *prenode = NULL;
    struct ListNode *curnode = head;

    while(curnode){
        if(!prenode){
            prenode = curnode;
            curnode = curnode->next;
        }else{
            if(curnode->val == prenode->val){
                struct ListNode *temp = curnode;
                prenode->next = curnode->next;
                curnode = curnode->next;
                free(temp);
            }else{
                prenode = curnode;
                curnode = curnode->next;
            }
        }
    }
    return head;
}
struct ListNode* createnode(int val){
    struct ListNode *pnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    pnode->val = val;
    pnode->next = NULL;
    return pnode;
}



void append(struct ListNode **head, int val)
{
    struct ListNode *node = createnode(val);
    if (*head == NULL){
        *head = node;
        return;
    }
    struct ListNode *h = *head;
    while (h->next){
        h=h->next;
    }
    h->next = node;
}
void printlist(struct ListNode* head)
{
    //struct ListNode *cur = head;
    while(head){
        printf("%d ->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}


void freelist(struct ListNode* head)
{
    //struct ListNode *cur = head;
    while(head){
        struct ListNode *temp = head;
        head=head->next;
        free(temp);
    }
}

int main(int argc, char** argv)
{
    struct ListNode *lista = NULL;
    append(&lista,1);
    append(&lista,1);
    append(&lista,2);
    append(&lista,3);
    append(&lista,3);
    printlist(lista);
    struct ListNode *listnew = deleteDuplicates(lista);
    printlist(listnew);
    freelist(listnew);
    return 0;
}
