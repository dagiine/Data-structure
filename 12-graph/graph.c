#include "graph.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Шинэ граф үүсгэх
Graph *createGraph(int maxVertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->maxVertices = maxVertices;

    // Хоосон adjacency matrix үүсгэх
    graph->adj = malloc(maxVertices * sizeof(int *));
    for (int i = 0; i < maxVertices; i++) {
        graph->adj[i] = calloc(maxVertices, sizeof(int));
    }

    return graph;
}

// Ирмэг нэмэх
int addEdge(Graph *graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->maxVertices || dest >= graph->maxVertices)
        return 0;
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
    return 1;
}

// Ирмэг устгах
int removeEdge(Graph *graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->maxVertices || dest >= graph->maxVertices)
        return 0;
    graph->adj[src][dest] = 0;
    graph->adj[dest][src] = 0;
    return 1;
}

// Breadth-First (BF) traversal
void breadthFirst(Graph *graph, int src) {
    bool *visited = calloc(graph->maxVertices, sizeof(bool));
    int *queue = malloc(graph->maxVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[src] = true;
    queue[rear++] = src;

    while (front < rear) {
        int current = queue[front++];
        printf(" %d", current);

        for (int i = 0; i < graph->maxVertices; i++) {
            if (graph->adj[current][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    free(visited);
    free(queue);
}

void dfsHelper(Graph *graph, int current, bool *visited) {
    visited[current] = true;
    printf(" %d", current);

    for (int i = 0; i < graph->maxVertices; i++) {
        if (graph->adj[current][i] && !visited[i]) {
            dfsHelper(graph, i, visited);
        }
    }
}

// Depth-First (DF) traversal
void depthFirst(Graph *graph, int src) {
    bool *visited = calloc(graph->maxVertices, sizeof(bool));
    dfsHelper(graph, src, visited);
    free(visited);
}

// Хамгийн богино зам олох
int findShortestPath(Graph *graph, int src, int dest, int *path) {
    bool *visited = calloc(graph->maxVertices, sizeof(bool));
    int *parent = malloc(graph->maxVertices * sizeof(int));
    int *queue = malloc(graph->maxVertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < graph->maxVertices; i++) parent[i] = -1;

    visited[src] = true;
    queue[rear++] = src;

    // BFS эхлүүлэх
    while (front < rear) {
        int curr = queue[front++];
        if (curr == dest) break;

        for (int i = 0; i < graph->maxVertices; i++) {
            if (graph->adj[curr][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                queue[rear++] = i;
            }
        }
    }

    // Зам олдсон эсэхийг шалгах
    if (!visited[dest]) {
        free(visited);
        free(parent);
        free(queue);
        return -1;
    }

    // Зам буцааж босгох
    int length = 0;
    for (int v = dest; v != -1; v = parent[v]) {
        path[length++] = v;
    }

    // Замыг зөв чиглэлд болгох (эсрэгээр нь байгаа учир)
    for (int i = 0; i < length / 2; i++) {
        int temp = path[i];
        path[i] = path[length - 1 - i];
        path[length - 1 - i] = temp;
    }

    free(visited);
    free(parent);
    free(queue);
    return length-1;
}

void printGraph(Graph *graph) {
  printf("#Graph {\n");
  for (int i = 0; i < graph->maxVertices; i++) {
    printf("#\t%d -> ", i);
    for (int j = 0; j < graph->maxVertices; j++) {
      if (graph->adj[i][j])
        printf("%d ", j);
    }
    printf("\n");
  }
  printf("#}\n");
}

// Төөрдөг байшинг дүрсэлж үзэх
void visualizeMaze(Graph *graph, int rows, int cols) {
    printf("#");
    for (int j = 0; j < cols; j++) {
        printf("+----");
    }
    printf("+\n");

    for (int i = 0; i < rows; i++) {
        printf("#");
        for (int j = 0; j < cols; j++) {
            int cell = i * cols + j;
            if (j > 0 && graph->adj[cell][cell-1]) {
                printf("    ");
            } else {
                printf("|    ");
            }
        }
        printf("|\n#");
        
        for (int j = 0; j < cols; j++) {
            int cell = i * cols + j;
            if (i < rows-1 && graph->adj[cell][cell+cols]) {
                printf("+    ");
            } else {
                printf("+----");
            }
        }
        printf("+\n");
    }
}

// Графыг устгах
void deleteGraph(Graph *graph) {
  for (int i = 0; i < graph->maxVertices; i++)
    free(graph->adj[i]);
  free(graph->adj);
  free(graph);
}