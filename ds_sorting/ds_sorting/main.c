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

void Merge(int A[], int low, int mid, int high)
{
    int i =low, j = mid + 1, k = low;
    int B[100]; //auxilary array to be used for merging
    while (i <= mid && j <= high) {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++) { // let's not re-initialize the counter again, because we copying the remaining elements
        B[k++] = A[i];
    }
    for (; j <= high; j++) {// any of one loop will be executed
        B[k++] = A[j];
    }
    //let's copy the elements back to main array from auxilary array
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
    
}

void merge_sort_iterative(int A[], int size)
{
    int p, low, mid, high;
    for (p =2; p <= size; p = p *2) { // loop for passes
        for (int i = 0; i + p - 1 < size; i = i + p) { // loop for merging all the list in a single pass
            low = i;
            high = i + p - 1;
            mid = (low + high)/2;
            Merge(A, low, mid, high);
        }
    }
    if (p/2 < size) { // for left over elements
        Merge(A, 0, p/2 - 1, size);
    }
}

int main(int argc, const char * argv[]) {
    int A[] = {30, 7, 9, 100, 11, 23, 12, 43, 20, 4, INT32_MAX};
    int n = 11;
    for (int i = 0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    //bubble_sort(A, n);
    //insertion_sort(A, n);
    //selection_sort(A, n);
    //quick_sort(A, 0, 10);
    merge_sort_iterative(A, n);
    for (int i = 0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
