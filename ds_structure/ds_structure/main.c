
#include <stdio.h>

struct Rectangle
{
    int length; //takes 4 bytes
    int breadth; //takes 4 bytes
};

//examples of structure
//complex number in maths => a + ib where i = imaginary
struct ComplexNo
{
    int real;
    int imaginary;
};

struct Student
{
    int rollNumber;
    char name[25];
    char department[25];
    char address[50];
};

struct Card
{
    int faceValue;//1(A), 2, 3, 4, 5, 6, 7, 8, 9, 10, 11(J), 12(Q), 13(K)
    int shape;//Club, Diamond, Heart, Spade
    int color;//Black, Red
    
};


int main(int argc, const char * argv[]) {
    struct Rectangle r1; //declaration, will be created in the memory
    r1.breadth = 23;
    r1.length = 34;
    
    printf("%d\n", r1.length);
    
    //single line declaration & initialization
    struct Rectangle r2 = {12, 32345};
    printf("%d\n", r2.breadth);
    
    struct Card c;
    c.faceValue = 1;
    c.color = 0;
    c.shape = 1;
    
    struct Card c1 = {1, 1, 1};
    
    //creating the deck
     //array of structures 52 * 3(size of int) bytes = total
    
    struct Card deck[52] = {
        {1,0,1},
        {2,0,1}
    };
    
    //accessing the value
    printf("%d", deck[0].color);
    printf("%d", deck[0].faceValue);
    printf("%d", deck[0].shape);
    
    //pointer to structure
    struct Rectangle *rectPtr = &r2;
    (*rectPtr).length = 23; //complex syntax
    rectPtr->breadth = 34; //clean syntax
    
    //heap allocation
    struct Rectangle *rectPtr2;
    rectPtr2 = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    rectPtr2->breadth = 10;
    rectPtr->length = 123;
    
    return 0;
}
