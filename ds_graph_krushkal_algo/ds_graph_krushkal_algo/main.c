#include <stdio.h>
#include "limits.h"
#define I INT_MAX

//verteces and their cost
int edges[3][9] = {
    { 1, 1,  2,  2, 3,  4,  4,  5,  5},
    { 2, 6,  3,  7, 4,  5,  7,  6,  7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

//we are using disjoint subset
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1}; //7 vertices
int included[9] = {0};
int t[2][6];

void _union(int u, int v){
    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    }else{
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u){
    int x = u;
    int v = 0;
    while (set[x] > 0) {
        x = set[x];
    }
    while (u != x) {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

void main() {
    int i, j, k=0, u=0, v=0, min=I, n=7, e=9;
    i=0;
    while (i<n-1) {
        min = I;
        for (j=0; j<e; j++) {
            if (included[j]==0 && edges[2][j] < min) {
                u=edges[0][j];
                v=edges[1][j];
                k=j;
            }
        }
        if (find(u)!=find(v)) {
            t[0][i]=u;
            t[1][i]=v;
            _union(find(u),find(v));
            i++;
        }
        included[k]=1;
    }
    for (i=0; i<n-1; i++) {
        printf("%d,%d\n", t[0][i], t[1][i]);
    }
}
