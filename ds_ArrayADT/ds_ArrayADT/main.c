#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int *A;
    int size;
    int length;
};
void Dispaly(struct Array arr)
{
    printf("Entered elements are:");
    for (int i= 0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}
int main(int argc, const char * argv[]) {
    struct Array arr;
    printf("Enter size of Array");
    scanf("%d", &arr.size);
    arr.A = (int*)malloc(arr.size*sizeof(int)); //array inside heap
    arr.length = 0; //as of now there is no elements
    int count;
    printf("Enter count");
    scanf("%d", &count);
    printf("Enter elements");
    for (int i =0; i<count; i++)
        scanf("%d", &arr.A[i]);
    arr.length=count;
    Dispaly(arr);
    return 0;
}
