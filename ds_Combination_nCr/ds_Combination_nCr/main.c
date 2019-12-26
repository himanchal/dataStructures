
#include <stdio.h>

int get_combination(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return get_combination(n-1, r-1) + get_combination(n-1, r);
}

int fact(int n)
{
    if(n==0)return 1;
    return fact(n-1)*n;
}

int nCr(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r)*fact(n-r);
    return num/den;
}

int main(int argc, const char * argv[]) {
    printf("%d\n", get_combination(3, 2));
    printf("%d\n", nCr(3, 2));
    return 0;
}
