#include <stdio.h>
#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void Reverse(struct Array *arr)
{
    int *B, i, j;
    B = (int*)malloc(sizeof(int)*arr->length);
    for (i = arr->length-1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i<arr->length; i++)
        arr->A[i] = B[i];
}
void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Reverse2(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i<j; i++, j--)
        Swap(&arr->A[i], &arr->A[j]);
}
void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++) {
        printf("%d\t", arr.A[i]);
    }
}
int main(int argc, const char * argv[]) {
    struct Array arr = {
        {23, 43, 52, 13}, 10, 5
    };
    Reverse2(&arr);
    Display(arr);
    return 0;
}
