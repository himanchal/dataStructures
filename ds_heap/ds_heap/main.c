#include <stdio.h>

void Insert(int H[], int n){
    int i=n;
    int temp;
    temp = H[i];
    //compare and swap the values untill it reaches at it's right place or to the root
    while (i>1 && temp>H[i/2]) {
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
}

int Delete(int A[],  int n){
    int i, j,x;
    x = A[n];
    
}
int main(int argc, const char * argv[]) {
    int H[] = {0,2,5,8,9,4,10,7}; //ignore 0
    
    Insert(H, 2);
    Insert(H, 3);
    Insert(H, 4);
    Insert(H, 5);
    Insert(H, 2);
    return 0;
}
