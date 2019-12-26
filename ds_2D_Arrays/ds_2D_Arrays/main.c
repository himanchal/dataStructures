
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int A[3][4] = { //allocated in stack
        {
            12, 23, 34, 30
        },
        {
            10, 22, 45, 89
        },
        {
            65, 67, 98, 33
        }
    };
    
    for (int i=0; i<3; i++) {
        for (int j =0; j<4; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
    int *B[3]; //allocated in stack
    B[0] = (int*)malloc(4*sizeof(int)); //allocated in heap
    B[1] = (int*)malloc(4*sizeof(int)); //allocated in heap
    B[2] = (int*)malloc(4*sizeof(int)); //allocated in heap
    
    int **C; //heap
    C = (int**)malloc(3*sizeof(int*)); //heap
    C[0] = (int*)malloc(4*sizeof(int)); //heap
    C[1] = (int*)malloc(4*sizeof(int)); //heap
    C[2] = (int*)malloc(4*sizeof(int)); //heap
    return 0;
}
