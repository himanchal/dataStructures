#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

void Push(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Overflow\n");
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop(){
    int x = -1;
    if (top == NULL) {
        printf("Underflow\n");
    }else{
        struct Node *t;
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p;
    p = top;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    Push(10);
    Push(20);
    Push(30);
    Display();
    printf("Popped out %d \n", Pop());
    Display();
    return 0;
}
