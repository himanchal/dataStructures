
#include <stdio.h>
#define SIZE 8
#define I 32767

int cost_matrix [SIZE][SIZE] = {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
};

int near[SIZE] = {I, I, I, I, I, I, I, I};
int spanning_tree[2][6];


int main(int argc, const char * argv[]) {
    int min_edge = 0;
    int u = 0, v = 0; // for edge
    int n = 7, min = I, i, j;
    
    //to find the minimum cost edge from cost_matrix
    for (int i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) { //considering only upper triangle
            if (cost_matrix[i][j] < min) {
                min = cost_matrix[i][j];
                u = i;
                v = j; //here we got an minimum edge
            }
        }
    }
    
    //let's store this minimum edge into spanning tree;
    spanning_tree[0][0] = u;
    spanning_tree[1][0] = v;
    
    //initialization of near array
    near[u] = near[v] = 0;
    
    //update the near array
    for (i = 1; i<n; i++) {
        if (near[i] != 0) {
            if (cost_matrix[i][u] < cost_matrix[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    
    for (i = 1; i < n-1; i++) {
        min = I;
        for (j = 1; j < n; j++) {
            if (near[j] != 0 && cost_matrix[j][near[j]] < min ) {
                min_edge = j; // k will have the minimum value
                min = cost_matrix[j][near[j]];
            }
        }
        spanning_tree[0][i] = min_edge;
        spanning_tree[1][i] = near[min_edge];
        near[min_edge] = 0;
        
        //update near array to check whether other vertices are nearer to min_edge or not
        
        for (j = 1; j <=n; j++) {
            if (near[j] != 0 && cost_matrix[j][min_edge] < cost_matrix[j][near[j]]) {
                near[j] = min_edge;
            }
        }
        for (i = 0; i < n; i++) {
            printf("%d, %d", spanning_tree[0][i], spanning_tree[1][i]);
        }
    }
    return 0;
}
