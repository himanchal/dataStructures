#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
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

void merge_sort_recursive(int A[], int low, int high)
{
    int mid = 0;
    if (low < high) {
        mid = (low + high)/2;
        merge_sort_recursive(A, low, mid);
        merge_sort_recursive(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

int find_max(int A[], int size)
{
    int max = INT32_MIN;
    for (int i =0; i < size ; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void count_sort(int A[], int size)
{
    int i, j, *C;
    int max = find_max(A, size);
    /* create an auxiliary array. the size of this array would be equal as maximum
     element of input array*/
    C = (int *)malloc(sizeof(int) * (max +1));
    //initialize all the elements of auxiliary array with 0 value.
    for (i = 0; i < max +1 ; i++) {
        C[i] = 0;
    }
    
    for (i = 0; i < size; i++) {
        C[A[i]]++; //increase the element whose index is matching with input array's element
        //element of input array becomes the index of auxilary array
    }
    i = 0; j = 0;
    //this loop is basically copying the array from auxilary array to input array back
    while (j < max +1) {
        if (C[j] > 0) {
            A[i++] = j;
            C[j]--;
        }else
            j++;
    }
}

void shell_sort(int A[], int size){
    for (int gap = size/2; gap >= 1; gap /= 2) {
        for (int i = gap; i < size ; i++) {
            int temp = A[i];
            int j = i - gap;
            while (j >= 0 && A[j] > temp) {
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int A[] = {30, 7, 9, 100, 11, 23, 12, 43, 20, 4};
    int size = 10;
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    //bubble_sort(A, n);
    //insertion_sort(A, n);
    //selection_sort(A, n);
    //quick_sort(A, 0, 10);
    //merge_sort_iterative(A, n);
    //merge_sort_recursive(A, 0, 9);
    //count_sort(A, size);
    shell_sort(A, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
