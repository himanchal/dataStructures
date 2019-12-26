

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int *p;
    p = (int*)malloc(5 * sizeof(int)); //memory allocation on heap //'new' is the keyword in c++
    printf("Hello, World!\n");
    return 0;
}
