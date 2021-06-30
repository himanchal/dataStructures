#include <stdio.h>
#include <limits.h>
void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int a[], int n){ //select an index and find the right candidate for that index
    int i,j,k;
    for (i=0; i<n-1; i++) { //we started with index 0 i.e. smallest element will come to this index
        for (j=k=i; j<n; j++) {
            if (a[j]<a[k]) { //till we find the smallest element
                k=j; //move the pointers
            }
        }
        Swap(&a[i], &a[k]); //replace the selected index with the found value.
    }
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

int partition (int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do{
        do{i++;} while(A[i] <= pivot);
        do{j--;} while(A[j] > pivot);
        if (i < j) {
            Swap(&A[i], &A[j]);
        }
    }while(i < j);
    Swap(&A[l], &A[j]);
    return j;
}

void quick_sort(int A[], int low, int high)
{
    int j;
    if (low < high) {
        j = partition(A, low, high);
        quick_sort(A, low, j);
        quick_sort(A, j+1, high);
    }
}

int main(int argc, const char * argv[]) {
    int A[] = {3, 7, 9, 10, 11, 23, 12, 43, 20, 4, INT32_MAX};
    int n = 11;
    for (int i = 0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    //bubble_sort(A, n);
    //insertion_sort(A, n);
    //selection_sort(A, n);
    quick_sort(A, 0, 10);
    for (int i = 0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
