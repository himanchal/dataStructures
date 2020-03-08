#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    char A[] = "finding";
    int H[26]; //will work as hash table
    for (int i = 0; A[i] != '\0'; i++) {
        H[A[i] - 97] += 1;
    }
    for (int i =0; i<26; i++) {
        if (H[i] > 1) {
            printf("%c\n", i + 97);
            printf("%d\n", H[i]);
        }
    }
    return 0;
}
