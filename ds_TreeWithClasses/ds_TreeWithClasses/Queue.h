#ifndef Queue_h
#define Queue_h
using namespace std;
class Node{ //a node of a tree
public:
    Node *lChild;
    int data;
    Node *rChild;
};
class Queue{ //this queue should work upon that node. we will be storing the addresses of nodes while creating a tree to create the relation among nodes.
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(){
        this->front = this->rear = -1;
        this->size = 10;
        this->Q = new Node*[this->size]; //array created in heap
    }
    Queue(int size){
        this->front = this->rear = -1;
        this->size= size;
        this->Q = new Node*[this->size];
    }
    void Enqueue(Node *x);
    Node* Dequeue();
    int IsEmpty(){
        return front == rear;
    }
    void Dispaly();
};
void Queue::Enqueue(Node *x){
    if (rear == size - 1) {
        cout<<"Overlfow\n";
    }else{
        rear++;
        Q[rear] = x;
    }
}
Node* Queue::Dequeue(){
    Node *x = NULL;
    if (front == rear) {
        cout<<"Underflow\n";
    }else{
        x = Q[front+1];
        front++;
    }
    return x;
}
void Queue::Dispaly(){
    for (int i = front+1; i<=rear; i++) {
        cout<<Q[i]<<" ";
    }
    cout<<"\n";
}
#endif /* Queue_h */
