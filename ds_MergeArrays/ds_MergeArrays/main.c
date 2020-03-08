#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    for (int i=0; i<arr.length; i++)
        printf("%d\t", arr.A[i]);
}
struct Array* MergeArrays(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j=0, k=0;
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array)); //array is created in heap can be returned and be used inside main function
    while (i < arr1->length && j < arr2->length){
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i <= arr1->length; i++)
        arr3->A[k++] = arr1->A[i++];
    for (; j <= arr2->length; j++)
        arr3->A[k++] = arr2->A[j++];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
    
}
int main(int argc, const char * argv[]) {
    struct Array arr1 = {
        {12, 43, 34, 45, 56}, 10, 5
    };
    struct Array arr2 = {
        {21, 32, 10, 45, 29}, 10, 5
    };
    struct Array *arr3;
    Display(arr1);
    printf("\n=====================\n");
    Display(arr2);
    arr3 = MergeArrays(&arr1, &arr2);
    printf("\n=====================\n");
    Display(*arr3);
    return 0;
}
