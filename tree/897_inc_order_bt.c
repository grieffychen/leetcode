/*
897. Increasing Order Search Tree
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* create_node(int val);

struct TreeNode* create_node(int val)
{
    struct TreeNode* node =(struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
#if 1
struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode *curnode = root; 
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode*)*100);
    struct TreeNode **arr = (struct TreeNode **)malloc(sizeof(struct TreeNode*)*100);
    int top = -1;
    int incidx = 0;
    printf("increasingBST\n");
    while( curnode || top!=-1){
        
        //printf("val=%d\n",curnode->val);
        if(curnode){
            stack[++top] = curnode;
            //printf("c=%p l=%p r=%p\n",curnode,curnode->left,curnode->right);
            curnode = curnode->left;
        }else{
            //printf("%d->",curnode->val);
            //printf("top=%d\n",top);
            struct TreeNode* node = stack[top];
            //printf("cur=%p r=%p\n",node,node->right);
            top--;
            //printf("%p\n",node);
            printf("%p :%d->\n",node,node->val);
            arr[incidx] = node;
            incidx++;
            curnode = node->right;
        }
    }
    
    for(int i =1;i<incidx;i++){
        arr[i-1]->left = NULL;
        arr[i-1]->right=arr[i];
        printf("n %p r =%p\n",arr[i-1],arr[i-1]->right);
    }
    arr[incidx-1]->left = NULL;
    arr[incidx-1]->right = NULL;
    printf("n %p r =%p\n",arr[incidx-1],arr[incidx-1]->right);
    struct TreeNode *newroot = arr[0]; 
    printf("NULL\n");
    if(stack)
        free(stack);
    if(arr)
        free(arr);
    return newroot;   
}
#else
struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode *curnode = root; 
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode*)*100);
    //struct TreeNode **incarr = (struct TreeNode **)malloc(sizeof(struct TreeNode*)*100);
    //struct TreeNode* stack[100];// = (struct TreeNode **)malloc(sizeof(struct TreeNode*)*100);
    struct TreeNode *pre = NULL; 
    struct TreeNode *newroot = NULL; 
    int top = -1;
    int incidx = 0;
    printf("increasingBST\n");
    while( curnode || top!=-1){
        
        //printf("val=%d\n",curnode->val);
        if(curnode){
            stack[++top] = curnode;
            printf("c=%p l=%p r=%p\n",curnode,curnode->left,curnode->right);
            curnode = curnode->left;
        }else{
            //printf("%d->",curnode->val);
            //printf("top=%d\n",top);
            struct TreeNode* node = stack[top];
            printf("cur=%p r=%p\n",node,node->right);
            if(top == 0){
                node->left = NULL;
                node->right = NULL;
            }
            top--;
            //printf("%p\n",node);
            printf("%d->\n",node->val);
            if(pre){
                pre->right = node;
                pre->left = NULL;
                printf("pre =%p l=%p r=%p v=%d\n",pre,pre->left,pre->right,pre->val);
            }else{
                newroot = node;
                newroot->left=NULL;
                //newroot->right = NULL;
                printf("newroot =%p %d\n",newroot,newroot->val);
            }
            pre = node;
            
            //printf("%d->",node->val);
            //printf("cur=%p r=%p\n",curnode,node->right);
            curnode = node->right;
        }
    }
    printf("NULL\n");
    if(stack)
        free(stack);
    return newroot;   
}
#endif

void inorder_print(struct TreeNode* root) 
{
    struct TreeNode* cur = root;
    struct TreeNode** stack = (struct TreeNode**) malloc(sizeof(struct TreeNode*) *100);
    int top = -1;
    while(cur ||top!=-1){
        if(cur){
            stack[++top] = cur;
            cur=cur->left;
        }else{
            struct TreeNode* n = stack[top];
            top--;
            printf("%d->",n->val);
            cur=n->right;
        }
    }
    printf("NULL\n");
    if(stack)
        free(stack);
}

int main(const int argc, const char **argv)
{
    struct TreeNode* n5 = create_node(5);
    struct TreeNode* n3 = create_node(3);
    struct TreeNode* n6 = create_node(6);
    struct TreeNode* n2 = create_node(2);
    struct TreeNode* n4 = create_node(4);
    struct TreeNode* n8 = create_node(8);
    struct TreeNode* n1 = create_node(1);
    struct TreeNode* n7 = create_node(7);
    struct TreeNode* n9 = create_node(9);
#if 1
    n5->left = n3;
    n5->right = n6;
    n6->left = n8;
#else
    n5->left = n3;
    n5->right = n6;
    n3->left = n2;
    n3->right = n4;
    n6->right = n8;
    n2->left = n1;
    n8->left = n7;
    n8->right = n9;
#endif    
    struct TreeNode *inctree=increasingBST(n5);
    inorder_print(inctree);
    //inorder_print(n5);
    return 0;
}