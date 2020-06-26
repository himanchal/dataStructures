

#ifndef Queue_h
#define Queue_h

struct Node{ //node to store the tree's elements
    struct Node *lChild;
    int data;
    struct Node *rChild;
};

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q; //going to store pointer of type node
};
void Create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (struct Node **)malloc(sizeof(struct Node *) * q->size); //node type pointer to a pointer (array of pointers)
}
void Enqueue(struct Queue *q, struct Node *x){
    if (q->rear == q->size-1) {
        printf("Overflow\n");
    }else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}
struct Node* Dequeue(struct Queue *q){
    struct Node *x = NULL;
    if (q->front == q->rear) {
        printf("Underflow\n");
    }else{
        q->front++;
        x = q->Q[q->front]; //copying the first value of array Q into x
    }
    return x;
}

int IsEmpty(struct Queue q){
    return q.front == q.rear;
}

#endif /* Queue_h */
