#include <stdio.h>
#include <stdalign.h>
#include <limits.h>
#include <ctype.h>

#define K 11

void find_min_max(int *min, int *max, int *array, int i, int N){
    if (i>=N){
        return;
    }
    if ((*min) > (*array)){
        *min = *array;
        
    }
    if ((*max) < (*array)){
        *max = *array;
       
    }
    find_min_max(min,max,array+1,i+1,N);
    return;
}

int main(void ){ 
    FILE *fp;
    int min, max;

    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("File open err");
        return 1;
    }
    char c;
    int array[K];
    int ar = 0;
    while (fscanf(fp, "%c", &c)!=EOF)
    {
        /* code */
       
        if (c == '\n'|| ar>=K){
            array[ar] = -1;
            break;
        }
        if (isdigit((unsigned char)c) ){ 
            array[ar++]=c-'0';
        }
        
    }

    min = INT_MAX;
    max = INT_MIN;

    find_min_max(&min,&max,&array[0],0,ar);
    printf("%d %d %d", min,max, array[ar]);

    fclose(fp);
    return 0;
}