#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *previous;
    int data;
    struct Node *next;
}*first = NULL;

void Create(int A[], int n){
    struct Node *t, *last;
    int i;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->previous = first->next = NULL;
    last = first;
    
    for (i = 1; i<n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->previous = last;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p){
    while (p) {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
int Count(struct Node  *p){
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if (index < 0 || index > Count(p)) {
        return;
    }
    if (index == 0) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->previous = NULL;
        t->next = first;
        first->previous = t;
        first = t;
    }else{
        for (i = 0; i<index-1; i++) {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->previous = p;
        t->next = p->next;
        if (p->next) {
            p->next->previous = t;
        }
        p->next = t;
    }
}
int Delete(struct Node *p, int index){
    int x = -1;
    int i;
    if (index < 1 || index > Count(p)) {
        return -1;
    }
    if (index == 1) {
        first = first->next;
        if (first) {
            first->previous = NULL;
        }
        x = p->data;
        free(p);
    }else{
        for (i = 0; i<index-1; i++) {
            p = p->next;
        }
        p->previous->next = p->next;
        if (p->next) {
            p->next->previous = p->previous;
        }
        x = p->data;
        free(p);
    }
    return x;
}
void Reverse(struct Node *p){
    struct Node *temp;
    while (p!= NULL) { //swap the pointers
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        if (p && p->next == NULL) {
            first = p;
        }
    }
}

int main(int argc, const char * argv[]) {
    int A[] = {12, 34, 54, 64, 45};
    Create(A, 5);
    //Insert(first, 3, 100);
    //Insert(first, 1, 400);
    //Insert(first, 0, 0);
    //printf("Deleted element %d \n", Delete(first, 4));
    printf("Total elements: %d \n", Count(first));
    Reverse(first);
    Display(first);
    return 0;
}
