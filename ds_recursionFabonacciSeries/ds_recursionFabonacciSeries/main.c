#include <stdio.h>
int fib(int n)
{
    int t0 = 0;
    int t1 = 1;
    int s = 0;
    int i;
    if (n <= 1)
        return n;
    for (i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int F[10];

int mFib(int n)
{
    if (n <= 1 ) {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1) {
            F[n - 2] = mFib(n - 2);
        }
        if (F[n - 1] == -1) {
            F[n - 1] = mFib(n - 1);
        }
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int rFib(int n)
{
    if (n <= 1) return n;
    return rFib(n - 2) + rFib(n - 1);
}

int main(int argc, const char * argv[]) {
    printf("%d\n", fib(8));
    printf("%d\n", rFib(8));
    
    //memoization
    int i;
    for (i = 0; i < 10; i++) {
        F[i] = -1;   //-1 doesn't fall in fibonacci series
    }
    
    printf("%d\n", mFib(8));
    
    return 0;
}
