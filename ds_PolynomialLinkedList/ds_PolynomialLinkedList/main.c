
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int expo;
    struct Node *next;
}*poly = NULL;

void Create(){
    struct Node *t, *last = NULL;
    int num, i;
    printf("Enter number of terms");
    scanf("%d", &num);
    printf("Enter each term with coeff and expo \n");
    for (i = 0; i < num; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->expo);
        t->next = NULL;
        if (poly == NULL) {
            poly = last = t;
        }else{
            last->next = t;
            last = t;
        }
    }
    
}

void Display(struct Node *p){
    while (p) {
        printf("%dx%d +", p->coeff, p->expo);
        p=p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x){
    long val = 0;
    while (p) {
        val += p->coeff * pow(x, p->expo);
        p = p->next;
    }
    return val;
}

int main(int argc, const char * argv[]) {
    Create();
    Display(poly);
    printf("%ld\n", Eval(poly, 1));
    return 0;
}
