/*
2487. Remove Nodes From Linked List

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105


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

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* create_node(int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void append_list(struct ListNode** head,int val)
{
    struct ListNode* node = create_node(val);
    if(*head ==NULL){
        *head = node;
        return;
    }
    struct ListNode* cur = *head;
    while(cur->next){
        cur=cur->next;
    }
    cur->next=node;
}

void pirnt_list(struct ListNode* head)
{
    struct ListNode* cur = head;
    while(cur){
        printf("%d-> ",cur->val);
        cur=cur->next;
    }
    printf("NULL\n");
}

void free_list(struct ListNode* head)
{
    while(head){
        struct ListNode* temp = head;
        head=head->next;
        free(temp);
    }
}

struct ListNode* reverselist(struct ListNode* head){
    //struct ListNode* cur = head;
    struct ListNode* pre = NULL;
#if 1
    while(head&&head->next){
        //printf("cur %p val=%d pre %p\n",head,head->val,pre);
        //head->next = pre;
        struct ListNode* next = head->next;
        head->next = pre;
        pre=head;
        head=next;
        //pre=head;
        //head=head->next;
        //temp->next = pre;
        //pre = temp;
    }
    //printf("cur %p val=%d pre %p\n",head,head->val,pre);
    if(head)
        head->next = pre;
    return head;
#else
    while(head&&head->next){
        printf("val=%d\n",head->val);
        //head->next = pre;
        struct ListNode* temp = head;
        head=head->next;
        temp->next = pre;
        pre = temp;
    }
    if(head)
        head->next = pre;
    return head;
#endif
}

struct ListNode* removeNodes(struct ListNode* head) {
    struct ListNode* revlist = reverselist(head);
    pirnt_list(revlist);
    struct ListNode* revhead = revlist->next;
    struct ListNode* revpre = revlist;
    while(revhead->next){
        //struct ListNode* revnext = revhead->next;
        if(revpre->val>revhead->val){
            struct ListNode* temp = revhead;
            revpre->next=revhead->next;
            revhead = revhead->next;
            free(temp);
        }else{
            revpre=revhead;
            revhead=revhead->next;
        }
    }
    if(revpre->val>revhead->val){
        struct ListNode* temp = revhead;
        revpre->next = NULL;
    }
    pirnt_list(revlist);

    return reverselist(revlist);;
}

int main(int argc, char** argv)
{
    int headval[] = {5,2,13,3,8};
    struct ListNode* head = NULL;
    
    for(int i = 0;i<sizeof(headval)/sizeof(int);i++){
        append_list(&head,headval[i]);
    }
    pirnt_list(head);
    //struct ListNode* revlist = reverselist(head);
    //pirnt_list(revlist);
    struct ListNode* anslist = removeNodes(head);
    pirnt_list(anslist);
    free_list(anslist);
    return 0;
}
