/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

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

#define bf 0
struct ListNode{
    int val;
    struct ListNode *next;    
};

struct ListNode* createnode(int val)
{
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void appendlist(struct ListNode** head,int val)
{
    //struct ListNode* lh = *head;
    //empty list
    if(*head ==NULL){
        struct ListNode* node = createnode(val);
        *head = node;
        return;
    }
    // not empty list 
    struct ListNode* lh = *head;
    struct ListNode* node = createnode(val);
    while(lh->next){
        lh=lh->next;
    }
    lh->next = node;
}

void printflist(struct ListNode* head){
    while(head){
        printf("%d->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

void freelist(struct ListNode** head){
    struct ListNode* h = *head;

    while(h){
        struct ListNode* temp = h;
        h=h->next;
        if(temp)
            free(temp);
    }
    *head = NULL;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode* temph = head;
    int lencnt = 0;
    while(temph){
        lencnt++;
        temph=temph->next;
    }
    int rmidx = lencnt-n+1;

    struct ListNode* rmh = head;
    struct ListNode* pre =NULL;
    int curidx = 0;
    while(rmh){
        curidx++;
        if(curidx == rmidx){
            if(pre){
                pre->next = rmh->next;
                struct ListNode* node = rmh;
                free(rmh);
                break;
            }else{
                if(lencnt == 1){
                    head = NULL;
                }else{
                    head = rmh->next;
                }
            }
            break;
        }
        pre=rmh;
        rmh=rmh->next;
    }

    return head;
}


int main(int argc, char** argv)
{
    //int l1[] = {2,4,3};
    //int l2[] = {5,6,4};
    //int nums[] = {1,2,3,4,5};
    int nums[] = {1};
    int n = 1;
    //int l1[] = {9};
    //int l2[] = {1,9,9,9,9,9,9,9,9,9};
    
    struct ListNode* list1 = NULL;
    for(int i = 0;i<sizeof(nums)/sizeof(int);i++){
        appendlist(&list1,nums[i]);
    }

    printflist(list1);

    struct ListNode* anslist = removeNthFromEnd(list1,n);
    printflist(anslist);
    freelist(&list1);
    return 0;
}
