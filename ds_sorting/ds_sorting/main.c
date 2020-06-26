#include <stdio.h>
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion_sort(int a[], int n){
    int i, j, x;
    for (i=1;i<n;i++) {
        j=i-1;
        x=a[i]; //start with second element, assume first element is already sorted.
        while (j>-1&&a[j]>x) { //keep shifting the elements one by one till they reach at their appropriate location
            a[j+1]=a[j]; //
            j--;
        }
        a[j+1]=x;
    }
}

void bubble_sort(int a[], int n){
    int i;
    int j;
    int isSorted = 1;
    for (i = 0; i <n-1; i++) {
        for (j = 0; j<n-i-1; j++) { // no need to compare the bottom element so j<n-i-1
            if (a[j] > a[j+1]) {
                Swap(&a[j], &a[j+1]);
                isSorted = 0; // if control has reached this line, the array was not sorted
            }
        }
        if (isSorted) {
            break; // no swapping happened in first pass i.e. array is already sorted
        }
    }
}
int main(int argc, const char * argv[]) {
    int A[] = {3, 7, 9, 10, 11, 23, 12, 43, 20, 4};
    int n = 10;
    for (int i = 0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    //bubble_sort(A, n);
    insertion_sort(A, n);
    for (int i = 0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
