#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *lChild;
    struct Node *rChild;
}*root = NULL;

void Insert(int key){
    struct Node *t = root;
    struct Node *r = NULL; // will work as a tail pointer;
    struct Node *p; //will be used to create a new node every time.
    if (root == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lChild = p->rChild = NULL; //initailly left and right child will be null, values will be assigned later
        root = p;
        return;
    }
    while (t!=NULL) {
        r = t; //r is a tail pointer, will be following t, which will ultimately help in inserting the node on its appropriate position
        if (key < t->data) {
            t = t->lChild;
        }else if(key > t->data){
            t = t->rChild;
        }else{
            return; //the key element is already present.
        }
    }
    //create new node
    
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lChild = p->rChild = NULL;
    
    //link the above node to existing binary search tree
    if (key < r->data) {
        r->lChild = p;
    }else{
        r->rChild = p;
    }
}

void Inorder(struct Node *p){
    if (p) {
        Inorder(p->lChild);
        printf("%d ", p->data);
        Inorder(p->rChild);
    }
}

struct Node* Search(int key){
    struct Node *t = root;
    while (t) {
        if (t->data == key) {
            return t;
        }else if(key < t->data){
            t = t->lChild;
        }else{
            t= t->rChild;
        }
    }
    return NULL;
}

struct Node* RecInsert(struct Node *p, int key){
    struct Node *t;
    if (p == NULL) { // key will be inserted only at the leaf node, till then function will call itself
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key; //actual data insertion;
        t->lChild = t->rChild = NULL; // initially both child references will be NULL
        return t;
    }
    if (key < p->data) {
        p->lChild = RecInsert(p->lChild, key);
    }else if(key > p->data){
        p->rChild = RecInsert(p->rChild, key);
    }
    return p;
}

int GetHeight(struct Node *p){
    if (p == NULL) return 0;
    int x, y;
    x = GetHeight(p->lChild);
    y = GetHeight(p->rChild);
    return x>y? x+1: y+1;
}

struct Node* GetInorderPredecessor(struct Node *p){
    while (p && p->rChild) {
        p = p->rChild;
    }
    return p;
}

struct Node* GetInorderSuccessor(struct Node *p){
    while (p && p->lChild) {
        p = p->lChild;
    }
    return p;
}

struct Node* Delete(struct Node *p, int key){
    if (p == NULL) {
        return NULL;
    }
    if (p->lChild == NULL && p->rChild == NULL) { // we have found the leaf node
        if (p == root) {
            root = NULL;
        }
        free(p);
        return NULL;
    }
    struct Node *q;
    
    if (key < p->data) {
        p->lChild = Delete(p->lChild, key);
    }else if(key > p->data){
        p->rChild = Delete(p->rChild, key);
    }else{ //find a replacement if the key is not a leaf node
        if (GetHeight(p->lChild) > GetHeight(p->rChild)){
            q = GetInorderPredecessor(p->lChild);
            p->data = q->data;
            p->lChild = Delete(p->lChild, q->data);
        }else{
            q = GetInorderSuccessor(p->rChild);
            p->data = q->data;
            p->rChild = Delete(p->rChild, q->data);
        }
    }
    return p;
}

int main(int argc, const char * argv[]) {
    //Insert(10);
    //Insert(5);
    //Insert(20);
    //Insert(8);
    //Insert(30);
    
    root = RecInsert(root, 23);
    RecInsert(root, 34);
    RecInsert(root, 12);
    RecInsert(root, 78);
    RecInsert(root, 67);
    
    Delete(root, 23);
    Inorder(root);
    printf("\n");
    struct Node* searchResult;
    searchResult = Search(30);
    if (searchResult) {
        printf("element found %d \n", searchResult->data);
    }else{
        printf("element not found\n");
    }
    return 0;
}
