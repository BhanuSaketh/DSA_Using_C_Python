#include <stdio.h>

#define V 8  

void printAdjacencyMatrix(int adjMatrix[V][V]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V] = {0};  
    int i, j;

    printf("Enter the edges between vertices (1 if there is an edge, 0 if none):\n");
    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            printf("Is there an edge between vertex %d and vertex %d? (1/0): ", i + 1, j + 1);
            scanf("%d", &adjMatrix[i][j]);
            adjMatrix[j][i] = adjMatrix[i][j];
        }
    }
    printAdjacencyMatrix(adjMatrix);

    return 0;
}
