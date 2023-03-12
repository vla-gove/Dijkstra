#include <stdio.h>
#include <limits.h>

#define V 7 // no of vertices in the graph

int mindistance(int distance[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && distance[v] <= min) {
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

void print(int distance[]) {
    printf("vertex           distance from source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int distance[V];
    bool sptSet[V]; // shortest path tree

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    distance[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = mindistance(distance, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    print(distance);
}

int main() {
    // initialize the graph
    int graph[V][V] = { {0, 2, 4, 0, 0, 0, 0},
                        {2, 0, 1, 4, 2, 0, 0},
                        {4, 1, 0, 2, 0, 4, 0},
                        {0, 4, 2, 0, 3, 1, 0},
                        {0, 2, 0, 3, 0, 0, 2},
                        {0, 0, 4, 1, 0, 0, 3},
                        {0, 0, 0, 0, 2, 3, 0} };

    dijkstra(graph, 0);

    return 0;
}