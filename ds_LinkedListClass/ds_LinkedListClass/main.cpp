#include <iostream>

class Node{
public:
    int data;
    Node *next;
};

class LinkedList{
private:
    Node *first;
public:
    LinkedList(){
        first = NULL;
    }
    LinkedList(int A[], int n){
        
    }
    ~LinkedList();
    void Display();
    void Insert(int index, int x);
    void Delete(int index);
    int Lenght();
};

int main(int argc, const char * argv[]) {
    
    return 0;
}

LinkedList::LinkedList(int A[], int n){
    Node *last, *t;
}
