#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph {
    int V;
    int** adjMatrix;
    struct Node** adjList;
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create adjacency matrix
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)calloc(V, sizeof(int));
    }

    // Create adjacency list
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    // Matrix
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;

    // List
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

void bfs(struct Graph* graph, int start) {
    int visited[100] = {0};
    int queue[100], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        struct Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
}

void dfsUtil(struct Graph* graph, int u, int visited[]) {
    visited[u] = 1;
    printf("%d ", u);

    struct Node* temp = graph->adjList[u];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            dfsUtil(graph, v, visited);
        }
        temp = temp->next;
    }
}

void dfs(struct Graph* graph, int start) {
    int visited[100] = {0};
    printf("\nDFS Traversal: ");
    dfsUtil(graph, start, visited);
}

void printAdjMatrix(struct Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printAdjList(struct Graph* graph) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printAdjMatrix(graph);
    printAdjList(graph);

    int start;
    printf("\nEnter starting node for BFS and DFS: ");
    scanf("%d", &start);

    bfs(graph, start);
    dfs(graph, start);

    return 0;
}
