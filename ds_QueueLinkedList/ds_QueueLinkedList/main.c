#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void Enqueue(int x){
    struct Node *t;
    t = malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Overflow\n");
    }else{
        t->data = x;
        t->next = NULL;
        if (front == NULL) {
            front = rear = t;
        }else{
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue(){
    int x = -1;
    struct Node *t;
    if (front == NULL) {
        printf("Underflow\n");
    }else{
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p = front;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    Enqueue(10);
    Enqueue(15);
    Enqueue(20);
    Enqueue(30);
    Display();
    printf("%d is deleted ", Dequeue());
    printf("\n");
    printf("%d is deleted ", Dequeue());
    printf("\n");
    Display();
    return 0;
}
