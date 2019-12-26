//
//  main.c
//  ds_IndirectRecursion
//
//  Created by hsingh on 12/12/19.
//  Copyright © 2019 hsingh. All rights reserved.
//

#include <stdio.h>

void funB(int n);

void funA(int n)
{
    if (n > 0) {
        printf("%d\t", n);
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1) {
        printf("%d\t", n);
        funA(n/2);
    }
}
int main(int argc, const char * argv[]) {
    funA(20);
    return 0;
}
