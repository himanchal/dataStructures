#include <stdlib.h>
#include <stdio.h>
int main(int argc, const char * argv[]) {
    char A[] = "shivam sharma";
    long int H = 0, x = 0;
    for (int i = 0; A[i] != '\0'; i++) {
        x = 1;
        x = x<<(A[i] - 97); //based on the ASCII value of lower case alphabets, subtract 97 from every char
        if ((x&H) > 0) //masking
            printf("%c is duplicate\n", A[i]);
        else
            H = x|H; //merging
    }
    return 0;
}
