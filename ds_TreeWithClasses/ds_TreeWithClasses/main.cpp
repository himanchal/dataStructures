#include <iostream>
#include "Queue.h"

class Tree{
public:
    Node *root;
    Tree(){
        root = NULL;
    }
    void CreateTree();
    void TraversePreorder(Node *p);
    void TraversePostorder(Node *p);
    void TraverseInorder(Node *p);
    void TraverseLevelOrder(Node *p);
    int GetTreeHeight(Node *root);
};

void Tree::CreateTree(){
    Node *p, *t;
    int x;
    Queue q(100);
    cout<<"Enter root value: ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lChild = root->rChild = NULL;
    q.Enqueue(root);
    while (!q.IsEmpty()) {
        p = q.Dequeue();
        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->lChild = t;
            q.Enqueue(t);
        }
        cout<<"Enter right child of "<<p->data<<": ";
        cin>>x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->rChild = t;
            q.Enqueue(t);
        }
    }
}

void Tree::TraversePreorder(Node *p){
    if (p != NULL) {
        cout<<p->data;
        TraversePreorder(p->lChild);
        TraversePreorder(p->rChild);
    }
}

void Tree::TraverseInorder(Node *p){
    if (p != NULL) {
        TraversePreorder(p->lChild);
        cout<<p->data;
        TraversePreorder(p->rChild);
    }
}

void Tree::TraversePostorder(Node *p){
    if (p != NULL) {
        TraversePostorder(p->lChild);
        TraversePostorder(p->rChild);
        cout<<p->data<<" ";
    }
}

int Tree::GetTreeHeight(Node *root){
    int x = 0; int y = 0;
    if (root == 0) {
        return 0;
    }
    x = GetTreeHeight(root->lChild);
    y = GetTreeHeight(root->rChild);
    if (x > y) {
        return x + 1;
    }else{
        return y + 1;
    }
}


int main(int argc, const char * argv[]) {
    Tree t;
    t.CreateTree();
    t.TraversePostorder(t.root);
    return 0;
}
