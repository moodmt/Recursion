#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
    /* data */
    int value;
    struct node *next;
}node_t;


void free_list(node_t *head, int n){
printf("\n");
    node_t *q;
    int cnt = 0;
   while (head!=NULL)
   {
    /* code */
    
        q = head->next;
        free(head);
        printf("node %d freed", cnt);
        cnt++;
        head = q;
   }
}

void tailToHead(node_t *head){
    if (head == NULL){
        return;
    }

    printf("%d ", head->value);
    tailToHead(head->next);
    return;
}

void headToTail(node_t *head){
    if (head == NULL){
        return;
    }

    
    headToTail(head->next);
    printf("%d ", head->value);
    return;
}

int main(void ){

    int list_int [] = {1,2,3,4,5,6};
    int cnt = 0;
    int si = sizeof(list_int) / sizeof(int);
    
    node_t *head,*p;
    
    head = NULL;
    for (int i = 0; i < si; i++)
    {
        p = (node_t *) malloc(sizeof(node_t));
        if (p == NULL){
            printf("allocation err");
            return 1;
        }
        p->value = list_int[i];
        p->next = head;
        head = p;
        printf("%d allocated ", cnt);
        cnt++;
    }
    
    printf("\nList tail to head:\n");
    tailToHead(head);
    printf("\n");
    headToTail(head);
    
    free_list(head, si);
    
    
    return 0;
}