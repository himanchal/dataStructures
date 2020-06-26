#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
struct Node *root = NULL;
void CreateTree(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    Create(&q, 100);
    printf("Enter root value");
    scanf("%d", &x);
    root = malloc(sizeof(struct Node));
    root->data = x;
    root->lChild = root->rChild = NULL; // as of now leaft node
    Enqueue(&q, root);
    while (!IsEmpty(q)) {
        p = Dequeue(&q);
        printf("Enter Left Child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = malloc(sizeof(struct Node));
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->lChild = t;
            Enqueue(&q, t);
        }
        printf("Enter Right Child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            t = malloc(sizeof(struct Node));
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->rChild = t;
            Enqueue(&q, t);
        }
    }
}
void TraversePreOrder(struct Node *p){
    if (p) {
        printf("%d ", p->data);
        TraversePreOrder(p->lChild);
        TraversePreOrder(p->rChild);
    }
}

void TraverseInOrder(struct Node *p){
    if (p) {
        TraverseInOrder(p->lChild);
        printf("%d ", p->data);
        TraverseInOrder(p->rChild);
    }
}

void TraversePostOrder(struct Node *p){
    if (p) {
        TraversePostOrder(p->lChild);
        TraversePostOrder(p->rChild);
        printf("%d ", p->data);
    }
}

int CountNode(struct Node *root){
    if (root) {
        return CountNode(root->lChild) + CountNode(root->rChild) + 1;
    }
    return 0;
}

int GetHeight(struct Node *root){
    int x = 0, y = 0;
    if (root == 0) {
        return 0;
    }
    x = GetHeight(root->lChild);
    y = GetHeight(root->rChild);
    if (x>y) {
        return x+1;
    }
    else{
        return y+1;
    }
}

void TraverseLevelOrder(struct Node *root){
    struct Queue q;
    Create(&q, 100);
    printf("%d ", root->data);
    Enqueue(&q, root);
    while (!IsEmpty(q)) {
        root = Dequeue(&q);
        if (root->lChild) {
            printf("%d ", root->lChild->data);
            Enqueue(&q, root->lChild);
        }
        if (root->rChild) {
            printf("%d ", root->rChild->data);
            Enqueue(&q, root->rChild);
        }
    }
}

int main(int argc, const char * argv[]) {
    CreateTree();
    printf("Node count: %d\n", CountNode(root));
    printf("Height: %d\n", GetHeight(root));
    //printf("\nLevel Order travesal:\n");
    //TraverseLevelOrder(root);
    //printf("\nPre Order traversal:\n");
    //TraversePreOrder(root);
    //printf("\nIn Order Traversal:\n");
    //TraverseInOrder(root);
    //printf("\nPost Order Traversal:\n");
    //TraversePostOrder(root);
    return 0;
}
