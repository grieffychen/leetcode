/*

1352. Product of the Last K Numbers

Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

 

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:

0 <= num <= 100
1 <= k <= 4 * 104
At most 4 * 104 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer.


 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>                      // File Control Definitions.
#include <termios.h>            // POSIX Terminal Control Definitions.
#include <unistd.h>                     // UNIX Standard Definitions.
#include <errno.h>                      // ERROR Number Definitions.
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


typedef struct {
    int count;
    int *prodbuf;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers * obj = malloc(sizeof(ProductOfNumbers));
    obj->prodbuf = (int*)malloc(sizeof(int)*40001);
    obj->count = 0;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if(num == 0){
        obj->count = 0;
    }else{
        if(obj->count==0)
            obj->prodbuf[obj->count] = num;
        else
            obj->prodbuf[obj->count] = obj->prodbuf[obj->count-1]*num;
        obj->count++;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if(k>obj->count){
        return 0;
    }else{
        //printf("[%d]=%d [%d]=%d\n",obj->count-1,obj->prodbuf[obj->count-1],obj->count-k-1,obj->prodbuf[obj->count-k-1]);
        int ans;
        if(k ==obj->count) 
            ans = obj->prodbuf[obj->count-1];
        else
            ans =obj->prodbuf[obj->count-1]/obj->prodbuf[obj->count-k-1];
        return ans;
    }
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    if(obj->prodbuf)
        free(obj->prodbuf);
    if(obj)
        free(obj);
}

int main(int argc, char**argv)
{
    ProductOfNumbers *pobj = productOfNumbersCreate();
    productOfNumbersAdd(pobj,3);
    productOfNumbersAdd(pobj,0);
    productOfNumbersAdd(pobj,2);
    productOfNumbersAdd(pobj,5);
    productOfNumbersAdd(pobj,4);
    
    printf("product k=2 : %d\n",productOfNumbersGetProduct(pobj,2));
    printf("product k=3 : %d\n",productOfNumbersGetProduct(pobj,3));
    printf("product k=4 : %d\n",productOfNumbersGetProduct(pobj,4));
    productOfNumbersAdd(pobj,8);
    printf("product k=2 : %d\n",productOfNumbersGetProduct(pobj,2));

    productOfNumbersFree(pobj);
    return 0;
}
