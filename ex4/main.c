#include <stdio.h>
#include "dijkstra.h"

int main() {
    int n;
    printf("Enter number of vertices (<=100):\n");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    int graph[100][100];
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &graph[i][j]) != 1 || graph[i][j] < 0) {
                printf("Invalid edge weight.\n");
                return 1;
            }

    int src;
    printf("Enter source vertex:\n");
    if (scanf("%d", &src) != 1 || src < 0 || src >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(graph, src, n);
    return 0;
}
