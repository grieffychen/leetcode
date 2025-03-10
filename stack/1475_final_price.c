#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

int topidx = -1;
int *stack = NULL;
void push(int val)
{
    stack[++topidx] =val;
}

int pop()
{
    return stack[topidx--];
}

bool isempty()
{
    if(topidx ==-1)
        return true;
    else
        return false;
}

int top()
{
    return stack[topidx];
}

int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    stack = (int*)malloc(pricesSize*sizeof(int));
    int *ans = (int*)malloc(pricesSize*sizeof(int));
    *returnSize = pricesSize;
    push(0);

    for(int i = pricesSize-1;i>=0;i--){
        int curprice = prices[i];
        while((top()>curprice) &&(!isempty())){
            pop();
        }
        ans[i] = curprice-top();
        push(curprice);
    }
    if(stack)
        free(stack);
    return ans;
}


int main(const int argc, const char **argv)
{
    int price[] = {8,4,6,2,3};
    int len = sizeof(price)/sizeof(int);
    printf("original price = ");
    for (int i = 0;i<len;i++)
        printf("%d ",price[i]);
    printf("\n");
    int retlen =0;
    int *disprice = finalPrices(price,len,&retlen);


    printf("discount price = ");
    for (int i = 0;i<len;i++)
        printf("%d ",disprice[i]);
    printf("\n");
    if(disprice)
        free(disprice);
    return 0;
}