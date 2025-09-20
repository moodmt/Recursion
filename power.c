#include <stdio.h>
#include <stdalign.h>

int power (int n, int x){
    if (n==0){
        return 1;
    }
    return x * power(n-1,x);
}

int main(void ){
    int x=2, n = 3;

    int result = power (n,x);
    printf("%d " , result);
    return 0;
}