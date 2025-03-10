/*

590. N-ary Tree Postorder Traversal
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:


Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
Example 2:


Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.

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


struct Node {
    int val;
    int numChildren;
    struct Node** children;
};
 






struct Node* create_node(int val , int nf_child)
{
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->val = val;
    n->numChildren = nf_child;
    printf("create node %d nfchild=%d\n",n->val,nf_child);
    if(nf_child==0)
        n->children = NULL;
    else{
        n->children = (struct Node**)malloc(sizeof(struct Node*)*nf_child);
        for(int i = 0;i<nf_child;i++){
            n->children[i] = NULL;
        }
    }
    printf("node=%p\n",n);
    return n;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#if 0
void postoder_traversal(struct Node* root)
{
    if(root){
        for(int i =0;i<root->numChildren;i++){
            postoder_traversal(root->children[i]);
        }
        printf("val=%d\n",root->val);
        //buf[(*len)] = root->val;
    }else
        return;
}
#else

#if 1
void postoder_traversal(struct Node* root , int* len,int* buf)
{
    printf("root=%p\n",root);
    if(!root)
        return;
    //if(root)
        for(int i =0;i<root->numChildren;i++){
            postoder_traversal(root->children[i],len,buf);
        }
        printf("val=%d\n",root->val);
        buf[(*len)] = root->val;
        printf("buf [%d] %d\n",*len,buf[(*len)] );
        (*len)++;
        printf("len=%d\n",*len);
        printf("===========\n");
    //}else{
    //    printf("ret\n");
    //    return;
    //}
}
#else
void postoder_traversal(struct Node* root , int* len,int* buf)
{
    printf("root=%p\n",root);
    if(root==NULL)
        return;
    for(int i =0;i<root->numChildren;i++){
        postoder_traversal(root->children[i],len,buf);
    }
        printf("val=%d\n",root->val);
    buf[(*len)++] = root->val;
        //printf("buf [%d] %d\n",*len,buf[(*len)] );
    //(*len)++;
        //printf("len=%d\n",*len);
        //printf("===========\n");
    //}else{
    //    printf("ret\n");
    //    return;
    //}
}
#endif

void postordertravel(struct Node* root, int* returnSize,int*v){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->numChildren;i++){
        postordertravel(root->children[i], returnSize,v);
    }
    v[(*returnSize)++]=root->val;

}
#if 0
void print_preorder(struct Node* root,int *len,int *buf)
{
    if(root){
        printf("len=%d %d \n",*len,root->val);
        buf[(*len)] = root->val;
        (*len)++;
        for(int i = 0;i<root->numChildren;i++){
            print_preorder(root->children[i],len,buf);
        }
    }
}
#endif
#endif

int* postorder(struct Node* root, int* returnSize) {
    int *ansarr = (int*) malloc(sizeof(int)*10000);
    memset(ansarr,0,sizeof(int)*10000);
    //int *ansarr = (int*) malloc(sizeof(int)*10);
    //int ansarr[10];
    int len = 0;
    printf("--------------------\n");
    postoder_traversal(root,&len,ansarr);
    //postoder_traversal(root,returnSize,ansarr);
    //postordertravel(root,&len,ansarr);
    //postoder_traversal(root);
    *returnSize = len;
    //return &ansarr[0];
    return ansarr;
} 



int main(const int argc, const char **argv)
{
    struct Node* naroot = create_node(1,3);
    struct Node* n3 = create_node(3,2);
    struct Node* n2 = create_node(2,0);
    struct Node* n4 = create_node(4,0);
    struct Node* n5 = create_node(5,0);
    struct Node* n6 = create_node(6,0);
    naroot->children[0] = n3;
    naroot->children[1] = n2;
    naroot->children[2] = n4;
    n3->children[0] = n5;
    n3->children[1] = n6;
    int retlen = 0;
    int *ansarr = postorder(naroot,&retlen);
    for(int i = 0;i<retlen;i++)
        printf("%d ->",ansarr[i]);
    printf("NULL\n");

    if(ansarr)
        free(ansarr);
    return 0;
}