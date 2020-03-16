#include <stdlib.h>
#include <stdio.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(sizeof(int) * q->size);
}
void Enqueue(struct Queue *q, int x){
    if (q->rear == q->size-1) {
        printf("Overflow\n");
    }else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int Dequeue(struct Queue *q){
    int x = -1;
    if (q->front == q->rear) {
        printf("Underflow\n");
    }else{
        q->front++;
        x = q->Q[q->front]; //copying the first value of array Q into x
    }
    return x;
}
void Display(struct Queue q){
    for (int i = q.front + 1; i<=q.rear; i++) {
        printf("%d ", q.Q[i]); //accessing the value from Array Q which is inside structure Queue
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    struct Queue q;
    Create(&q, 5);
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Display(q);
    Dequeue(&q);
    Display(q);
    return 0;
}
