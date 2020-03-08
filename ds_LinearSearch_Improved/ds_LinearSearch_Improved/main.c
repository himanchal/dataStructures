#include <stdio.h>
#include <stdlib.h>
struct Array {
    int A[10];
    int size;
    int lenght;
};
void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->lenght; i++)
        if (key == arr->A[i])
        {
            Swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    return -1;
}
int main(int argc, const char * argv[]) {
    struct Array arr = {
        {2,3,4,5},10, 5
    };
    
    printf("%d\n", LinearSearch(&arr, 5));
    return 0;
}
