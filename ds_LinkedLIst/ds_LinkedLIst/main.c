#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;      //self referential structure
}*first; //created a default object, simliar to header
//this becomes a global pointer
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
void DisplayLinkedList(struct Node *p){
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
void RecursiveDisplay(struct Node *p){
    if (p != NULL) {
        printf("%d ", p->data);     //head recursion
        RecursiveDisplay(p->next);
        printf("%d ", p->data); // tail recursion
    }
}
int main(int argc, const char * argv[]) {
    int A[] = {3, 5, 1, 7, 10, 15};     //data for linked list
    CreateLinkedList(A, 5);
    RecursiveDisplay(first);
    return 0;
}
