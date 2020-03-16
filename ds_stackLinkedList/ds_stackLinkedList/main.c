#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
}*top = NULL;

void Push(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL) {
        printf("Overflow\n");
    }else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop(){
    int x = -1;
    if (top == NULL) {
        printf("Underflow\n");
    }else{
        struct Node *t;
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p;
    p = top;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int IsBalanced(char *exp){ //parantheseis matching: this program verifies only the number of parenthesis not the position
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            Push(exp[i]);
        }else if(exp[i] == ')'){
            if (top == NULL) {
                return 0;
            }
            Pop();
        }
    }
    if (top == NULL) {
        return 1;
    }else{
        return 0;
    }
}

int GetPrecedence(char x){
    if (x == '+' || x == '-') {
        return 1;
    }else if(x == '*' || x == '/'){
        return 2;
    }
    return 0;
}

int IsOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/') {
        return 0;
    }else{
        return 1;
    }
}

char* InfixToPostfix(char *infix){
    char *postfix;
    long length = strlen(infix);
    postfix = (char *)malloc(sizeof(char)*(length+2));
    int i = 0, j =0;
    while (infix[i] != '\0') {
        if (IsOperand(infix[i])) {
            postfix[j++] = infix[i++];
        }else{
            if (GetPrecedence(infix[i]) > GetPrecedence(top->data)) {
                Push(infix[i++]);
            }else{
                postfix[j++] = Pop();
            }
        }
    }
    while (top != NULL) {
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int EvaluatePostfix(char *postfix){
    int i = 0;
    int x1, x2, r = 0;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (IsOperand(postfix[i])) {
            Push(postfix[i] - '0');//subtracting the ASCII Code of 0(Zero) or 48 also can be subtracted as input is string and all the operations will be performed based on the ASCII values
        }else{
            x2 = Pop();
            x1 = Pop();
            switch (postfix[i]) {
                case '+':
                    r = x1 + x2;
                    break;
                 case '-':
                    r = x1 + x2;
                    break;
                case '*':
                    r = x1 + x2;
                    break;
                case '/':
                    r = x1 / x2;
                    break;
                default:
                    break;
            }
            Push(r);
        }
    }
    return top->data;
}

int main(int argc, const char * argv[]) {
    //Push(10);
    //Push(20);
    //Push(30);
    //Display();
    //printf("Popped out %d \n", Pop());
    //Display();
    //char *exp = "((a+b)*(c+d))";
    //printf("%d\n", IsBalanced(exp));
    //char *infix = "a+b*c";
    //Push('#');
    //char *postfix = InfixToPostfix(infix);
    //printf("%s\n", postfix);
    char *postfixExprssion = "234*+82/-";
    printf("Result is %d\n", EvaluatePostfix(postfixExprssion));
    return 0;
}
