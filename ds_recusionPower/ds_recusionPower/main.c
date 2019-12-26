
#include <stdio.h>

int cal_pow(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return cal_pow(m, n - 1) * m;
}

int cal_pow_refactored(int m, int n)
{
    if (n == 0)
        return 1;
    else
        if (n % 2 == 0)
            return cal_pow_refactored(m * m , n/2);
        else
        return m * cal_pow_refactored(m * m, (n - 1)/2);
}

int main(int argc, const char * argv[]) {
    int r  = cal_pow_refactored(2, 9);
    printf("%d\n", r);
    return 0;
}
