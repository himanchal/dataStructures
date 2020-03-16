#include <iostream>
#include <stdlib.h>

using namespace std;

class Queue{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    Queue(){
        this->front = this->rear = -1;
        this->size = 10;
        this->Q = new int[this->size]; //array created in heap
    }
    Queue(int size){
        this->front = this->rear = -1;
        this->size= size;
        this->Q = new int[this->size];
    }
    void Enqueue(int x);
    int Dequeue();
    void Dispaly();
};

void Queue::Enqueue(int x){
    if (rear == size - 1) {
        cout<<"Overlfow\n";
    }else{
        rear++;
        Q[rear] = x;
    }
}

int Queue::Dequeue(){
    int x = -1;
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

int main(int argc, const char * argv[]) {
    Queue q(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.Enqueue(20);
    q.Dispaly();
    q.Dequeue();
    q.Dequeue();
    q.Dispaly();
    return 0;
}
