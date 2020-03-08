#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
int BinarySearch(int key, struct Array arr)
{
    int low = 0;
    int high = arr.length;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int bin_search_rec(int a[], int l, int h, int key)
{
    int mid;
    if (l <= h) {
        mid = (l + h) /2;
        if (key == a[mid])
            return mid;
        else if(key < a[mid])
            return bin_search_rec(a, l, mid - 1, key);
        else
            return bin_search_rec(a, mid + 1, h, key);
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    struct Array arr = {
        {12, 23, 34, 45, 56, 67, 78, 89, 90},
        10,
        9
    };
    printf("%d\n", BinarySearch(45, arr));
    printf("%d\n", bin_search_rec(arr.A, 0, arr.length, 45));
    return 0;
}
