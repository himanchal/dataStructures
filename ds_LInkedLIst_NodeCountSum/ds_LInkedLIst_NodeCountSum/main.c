#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first = NULL;
void CreateLinkedList(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p){
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int Count(struct Node *p){
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

int Max(struct Node *p){
    int max = INT32_MIN;
    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Delete(struct Node *p, int index){
    struct Node *q = NULL;
    int x =-1;
    if (index < 1 || index > Count(p)) {
        return -1;
    }
    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else{
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int main(int argc, const char * argv[]) {
    int A[] = {3, 55, 7, 10, 25};
    CreateLinkedList(A, 5);
    Display(first);
    Delete(first, 5);
    Display(first);
    //printf("Total Nodes: %d \n", Count(first));
    //printf("Max is: %d \n", Max(first));
    return 0;
}
