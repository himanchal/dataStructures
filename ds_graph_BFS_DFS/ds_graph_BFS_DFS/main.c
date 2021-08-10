//
//  main.c
//  ds_graph_BFS_DFS
//
//  Created by hsingh on 24/07/21.
//  Copyright © 2021 hsingh. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

void breadth_first_search(int graph[][7], int start, int n){
    int i = start;
    struct Queue_h q;
    int visitiedArray[7] = {0};
    printf("%d", i);//printing the starting vertex
    visitiedArray[i] = 1;
    enqueue(i);
}

int main(int argc, const char * argv[]) {
    int Graph[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("Hello, World!\n");
    return 0;
}
