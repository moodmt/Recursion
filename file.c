#include <stdio.h>
#include <stdlib.h>

int fibo(int n, int *known);

int main(void ){
    printf("hellow world\n");
    printf("this is the first ");
    int n = 10;
    int *known = (int *) malloc ((n+1) * sizeof(int));

    for (int i = 0; i <= n; i++){
        known[i] = -1;
    }
    fibo(n,known);
    printf("The list of fibbo is : ");
    for (int j=0;j<n;j++){
        printf("%d, ", known[j]);
    }
    

    free(known);
    return 0;
}

int fibo(int n, int *known){
    if (known[n] < 0){
        if (n==0 || n==1){
            known[n] = n;
        }else {
            known[n]= fibo(n-1, known) + fibo(n-2, known);
        }
    }
    return known[n];
}

