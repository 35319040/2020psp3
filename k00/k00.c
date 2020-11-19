#include <stdio.h>
 
int factorial(int n){

    int val;
    printf("call n=%d\n",n);
    if(n==1){
        return 1;
    }
    val=n*factorial(n-1);
    printf("return value=%d\n",val);
    return val;
}

int main(void){
    printf("10!=%d\n",factorial(10));
}