#include <stdio.h>
#include <stdlib.h>
struct Element{
    int i, j, x;
};
struct Sparse{
    int m, n, num;
    struct Element *element;
};
void Create(struct Sparse *s){
    printf("Enter dimensions");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero");
    scanf("%d", &s->num);
    s->element = (struct Element*)malloc(s->num*sizeof(struct Element));
    printf("Enter non-zero elements");
    for (int i = 0; i<s->num; i++) {
        scanf("%d%%d%d", &s->element[i].i, &s->element[i].j, &s->element[i].x);
    }
}
void Display(struct Sparse s){
    int i, j, k = 0;
    for (i = 0; i < s.m; i++) {
        for (j = 0; j < s.n; j++) {
            if (i == s.element[k].i && j == s.element[k].j) printf("%d ", s.element[k++].x);
            else printf("%d ", "0");
        }
    }
}
int main(int argc, const char * argv[]) {
    struct Sparse s;
    Create(&s);
    Display(s);
    return 0;
}
