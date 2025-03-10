/*
1669. Merge In Between Linked Lists

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.

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
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
}

void append_list(struct ListNode** head,int val)
{
    struct ListNode* n = create_node(val);
    if(*head == NULL){
        *head = n;
        return;
    }
    struct ListNode* cur = *head;
    while(cur->next){
        cur=cur->next;
    }
    cur->next = n;
}

void printlist(struct ListNode* lh)
{
    while(lh){
        printf("%d->",lh->val);
        lh=lh->next;
    }
    printf("NULL\n");
}

void freelist(struct ListNode* lh)
{
    while(lh){
        struct ListNode* temp = lh;
        lh=lh->next;
        free(temp);
    }
}

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* pre_nodea = NULL;
    struct ListNode* nodeb = NULL;
    struct ListNode* cur_list1 = list1;
    struct ListNode* pre = NULL;
    int nidx = 0;
    while(cur_list1){
#if 1
        if(nidx == a){
            pre_nodea = pre;
        }
        if(nidx == b){
            nodeb = cur_list1;
            break;
        }
#else
        if(pre!=NULL){
            if(pre->val == a)
                pre_nodea = pre;
        }
        if(cur_list1->val == b){
            nodeb = cur_list1;
            break;
        }
#endif
        nidx++;        
        pre = cur_list1;    
        cur_list1 = cur_list1->next;
    }
    // iterate list2 to end;
    struct ListNode* cur_list2 = list2;
    while(cur_list2->next){
        cur_list2=cur_list2->next;
    }
    if(pre_nodea)
        pre_nodea->next = list2;
    cur_list2->next = nodeb->next;
    return list1;
}

int main(int argc, char** argv)
{
    //list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
    int a = 3;
    int b = 4;
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;
    append_list(&list1,10);
    append_list(&list1,1);
    append_list(&list1,13);
    append_list(&list1,6);
    append_list(&list1,9);
    append_list(&list1,5);

    append_list(&list2,1000000);
    append_list(&list2,1000001);
    append_list(&list2,1000002);

    printlist(list1);
    printlist(list2);

    struct ListNode* anslist = mergeInBetween(list1,a,b,list2);
    printlist(anslist);
    freelist(anslist);
    //freelist(list2);
    return 0;
}
