
#include <iostream>

void Function(int *A, int n) // array is passed only by address, not by value
{
    //any changes here will reflect in the main changes
}

int* returnArray(int n) //retrurning an array
{
    int *p;
    p = (int*)malloc(n * sizeof(int));
    return (p);
}
int main(int argc, const char * argv[]) {
    int a[] = {1, 2, 3, 4, 5};
    
    Function(a, 5);
    int *A;
    A = returnArray(5);
    return 0;
}
