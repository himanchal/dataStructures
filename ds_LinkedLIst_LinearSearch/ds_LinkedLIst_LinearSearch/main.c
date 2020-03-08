#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first = NULL;
void CreateLinkList(int A[], int n){
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
}
struct Node * Linear_Search(struct Node*p, int key){
    while (p) {
        if (key == p->data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int Count(struct Node *p){
    int l = 0;
    while (p != NULL) {
        l++;
        p=p->next;
    }
    return l;
}
void Insert(struct Node *p, int x, int index){
    if (index < 0 || index > Count(p)) {
        return;
    }
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0) {
        t->next = first;
        first = t;
    }
    else{
        for (int i = 0; i < index -1 ; i++) {
            p = p->next;
            t -> next = p->next;
            p ->next = t;
        }
    }
}

void RemoveDuplicate(struct Node *p){
    struct Node *q = p->next;
    while (q != NULL) {
        if (p -> data != q ->data) {
            p = q;
            q = q -> next;
        }
        else{
            p -> next = q ->next;
            free(q);
            q = p -> next;
        }
    }
}

void Reverse1(struct Node *p){
    int *A, i = 0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int)*Count(p));
    while (q != NULL) {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL) {
        q -> data = A[i];
        q = q -> next;
        i--;
    }
}

void Reverse2(struct Node *p){ //we will be using sliding pointers concept
    struct Node *q = NULL;
    struct Node *r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void RecReverse(struct Node *q, struct Node *p){
    if (p) {
        RecReverse(p, p->next);
        p ->next = q;
    }else{
        first = q;
    }
}
int main(int argc, const char * argv[]) {
    //struct Node *temp = NULL;
    int A[] = {12, 32, 32, 35, 56, 75, 23, 89, 98};
    CreateLinkList(A, 8);
    //temp = Linear_Search(first, 23);
    //if (temp) printf("found %d\n", temp->data);
    //else printf("Not found\n");
    Display(first);
    printf("\n");
    //Insert(first, 10, 1);
    //RemoveDuplicate(first);
    RecReverse(NULL, first);
    Display(first);
    printf("\n");
    return 0;
}
