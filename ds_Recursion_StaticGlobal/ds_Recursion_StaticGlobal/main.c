

#include <stdio.h>
int x = 0;
int func(int n)
{
    static int y = 0;
    if (n > 0) {
        y++;
        return func(n - 1) + y;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int r;
    r = func(5);
    printf("%d \n", r);
    return 0;
}
