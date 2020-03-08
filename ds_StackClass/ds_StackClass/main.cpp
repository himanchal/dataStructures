#include <iostream>

class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top = nullptr;
    }
    void Push(int x);
    int Pop();
    void Display();
};

void Stack::Push(int x){
    Node *t = new Node();
    if (t == nullptr) {
        std::cout<<"Overflow";
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::Pop(){
    int x = -1;
    if (top == nullptr) {
        std::cout<<"Underflow";
    }else{
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::Display(){
    Node *p = top;
    while (p != nullptr) {
        std::cout<<p->data<<" ";
        p = p->next;
    }
    std::cout<<std::endl;
}

int main(int argc, const char * argv[]) {
    Stack stk;
    stk.Push(10);
    stk.Push(20);
    stk.Push(30);
    stk.Display();
    std::cout<<stk.Pop();
    return 0;
}
