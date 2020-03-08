#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void SortedInsert(struct Node *p, int x){
    struct Node *t, *q = NULL;
    t =  (struct Node *)malloc(sizeof(struct Node));
    t -> data = x;
    t -> next = NULL;
    if (first == NULL) {
        first = t;
    }
    else{
        while (p && p->data<x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t -> next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}
void Display(struct Node *p){
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main(int argc, const char * argv[]) {
    SortedInsert(first, 15);
    SortedInsert(first, 23);
    SortedInsert(first, 11);
    Display(first);
    printf("\n");
    return 0;
}
