#include <stdio.h>
#include <stdlib.h>
struct Term{
    int coeff;
    int exp;
};
struct Poly{
    int n;
    struct Term *terms;
};
void Create(struct Poly *p){
    int i;
    printf("Number of terms;");
    scanf("%d", &p->n);
    p->terms = (struct Term*)malloc(p->n*sizeof(struct Term));
    printf("enter terms");
    for (i = 0; i < p->n; i++) {
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
    
}
void Display(struct Poly p){
    int i;
    for (i = 0; i < p.n; i++) {
        printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    struct Poly p1;
    Create(&p1);
    Display(p1);
    return 0;
}
