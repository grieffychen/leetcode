/*
21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

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

typedef struct ListNode{
    int val;
    struct ListNode *next;
}list_node_t ,*plist_node_t;

plist_node_t mergeTwoLists(plist_node_t list1, plist_node_t list2){

    plist_node_t head = NULL;
    plist_node_t temp = NULL;
    if((list1==NULL)||(list2==NULL))
        return list1? list1:list2;
    if(list2->val>list1->val){
        head =list1;
        temp =list1;
        list1=list1->next;
    }else{
        head = list2;
        temp = list2;
        list2=list2->next;
    }

    //plist_node_t prenode= NULL;
    while (list1 &&list2){
        if(list1->val<list2->val){
            temp->next = list1;
            list1 = list1->next;
        }else{
            temp->next=list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    temp->next = (list1==NULL) ? list2:list1;

    return head;
}

plist_node_t createnode(int val){
    struct ListNode* node = malloc(sizeof(list_node_t));
    node->val = val;
    node->next = NULL;
}



void append(plist_node_t *head, int val)
{
    plist_node_t node = createnode(val);
    if(*head ==NULL){
        *head = node;
        return;
    }

    plist_node_t cur = *head;
    while(cur->next){
        cur= cur->next;
    }
    cur->next = node;
}
void printlist(plist_node_t head)
{
    while(head){
        printf("%d->",head->val);
        head=head->next;
    }
    printf("NULL\n");
}


void freelist(plist_node_t head)
{
    while(head){
        plist_node_t temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char** argv)
{
    plist_node_t list1 = NULL;
    append(&list1,1);
    append(&list1,2);
    append(&list1,5);
    printlist(list1);

    plist_node_t list2 = NULL;
    append(&list2,1);
    append(&list2,3);
    append(&list2,4);
    printlist(list2);
    plist_node_t head = mergeTwoLists(list1,list2);
    printlist(head);
    freelist(head);
    //freelist(list2);
    return 0;
}
