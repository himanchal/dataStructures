#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st){
    printf("Enter size");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st){
    for (int i = st.top; i >= 0; i--) {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void Push(struct Stack *st, int x){
    if (st->top == st->size) printf("Overflow\n");
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

int Pop(struct Stack *st){
    int x = -1;
    if (st->top == -1) {
        printf("Underflow\n");
    }else{
        x = st->S[st->top--];
    }
    return x;
}

int main(int argc, const char * argv[]) {
    struct Stack st;
    Create(&st);
    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);
    Push(&st, 60);
    Display(st);
    return 0;
}
