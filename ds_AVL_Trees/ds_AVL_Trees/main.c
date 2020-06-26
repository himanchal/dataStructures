#include <stdlib.h>
#include <stdio.h>

struct Node{
    struct Node *lChild;
    int data;
    int height; //height of left sub tree and right sub tree will be fetched to calculate the balance factor
    struct Node *rChild;
}*root = NULL;

int GetNodeHeight(struct Node *p){
    int hl, hr;
    hl = p && p->lChild? p->lChild->height: 0;
    hr = p && p->rChild? p->rChild->height: 0;
    return hl>hr? hl+1: hr+1;
}

int GetBalanceFactor(struct Node *p){
    int hl, hr;
    hl = p && p->lChild? p->lChild->height: 0;
    hr = p && p->rChild? p->rChild->height: 0;
    return hl - hr;
}

struct Node* LLRotation(struct Node *p){
    struct Node *pl = p->lChild;
    struct Node *plr = pl->rChild;
    plr->rChild = p;
    p->lChild = plr;
    p->height = GetNodeHeight(p);
    pl->height = GetNodeHeight(pl);
    if (root == p) {
        root = pl;
    }
    return pl; //the new root
}

struct Node* LRRotation(struct Node *p){
    return NULL;
}

struct Node* RRRotation(struct Node *p){
    return NULL;
}

struct Node* RLRotation(struct Node *p){
    return NULL;
}
struct Node* RecInsert(struct Node *p, int key){
    struct Node *t;
    if (p == NULL) { // key will be inserted only at the leaf node, till then function will call itself
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key; //actual data insertion;
        t->height = 1;
        t->lChild = t->rChild = NULL; // initially both child references will be NULL
        return t;
    }
    if (key < p->data) {
        p->lChild = RecInsert(p->lChild, key);
    }else if(key > p->data){
        p->rChild = RecInsert(p->rChild, key);
    }
    p->height = GetNodeHeight(p);
    if (GetBalanceFactor(p) == 2 && GetBalanceFactor(p->lChild) == 1) {
        //should perform LL Rotation
        return LLRotation(p);
    }else if(GetBalanceFactor(p) == 2 && GetBalanceFactor(p->lChild) == -1){
        return  LRRotation(p);
    }else if(GetBalanceFactor(p) == -2 && GetBalanceFactor(p->lChild) == -1){
        return  RRRotation(p);
    }lse if(GetBalanceFactor(p) == -2 && GetBalanceFactor(p->lChild) == 1){
        return  RLRotation(p);
    }
    return p;
}

int main(int argc, const char * argv[]) {
    root = RecInsert(root, 10);
    RecInsert(root, 5);
    RecInsert(root, 2);
    
    return 0;
}
