

#include <stdio.h>

//taylor series
double e(int x,  int n)
{
    static double p = 1;
    static double f = 1;
    double r;
    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int main(int argc, const char * argv[]) {
    printf("%lf\n", e(1, 10));
    return 0;
}
