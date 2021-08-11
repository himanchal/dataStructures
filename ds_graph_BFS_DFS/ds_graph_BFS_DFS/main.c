//
//  main.c
//  ds_graph_BFS_DFS
//
//  Created by hsingh on 24/07/21.
//  Copyright © 2021 hsingh. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

void breadth_first_search(int graph[][7], int starting_vertex, int size){
    int i = starting_vertex;
    //struct Queue_h q;
    int visitiedArray[7] = {0};
    printf("%d ", i);//printing the starting vertex
    visitiedArray[i] = 1;
    enqueue(i);
    while (!isEmpty()) {
        i = dequeue();
        for (int j = 1; j < size; j++) {
            if (graph[i][j] == 1 && visitiedArray[j] == 0) {
                printf("%d ", j);
                visitiedArray[j] = 1;
                enqueue(j);
            }
        }
    }
}

void depth_first_search(int graph[][7], int starting_vertex, int max_dimension){
    static int visitedArray[7] = {0};
    if (visitedArray[starting_vertex] == 0) {
        printf("%d ", starting_vertex);
        visitedArray[starting_vertex] = 1; //recursion trivial case
        for (int j = 1; j < max_dimension; j++) {
            if (graph[starting_vertex][j] == 1 && visitedArray[j] == 0){
                depth_first_search(graph, j, max_dimension); //recursive call
            }
        }
    }
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
    
    breadth_first_search(Graph, 1, 7);
    printf("\n");
    depth_first_search(Graph, 1, 7);
    return 0;
}
