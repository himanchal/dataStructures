

#include <stdio.h>

int fun(int n)
{
    if (n > 100)
        return n - 10;
    return fun(fun(n + 11));
    
}

int main(int argc, const char * argv[]) {
    int r;
    r = fun(1000);
    printf("%d\n", r);
    return 0;
}
