#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define INF 999999

//ARRAY VERSION

int minDistanceArray(int dist[], int visited[], int V) {
    int min = INF, index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstraArray(int **graph, int V, int src) {
    int dist[V], visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistanceArray(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nDijkstra Using Array:\n");
    for (int i = 0; i < V; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

//MIN HEAP VERSION

struct MinHeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

struct MinHeapNode* newNode(int v, int dist) {
    struct MinHeapNode* node = malloc(sizeof(struct MinHeapNode));
    node->v = v;
    node->dist = dist;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->pos = malloc(capacity * sizeof(int));
    heap->array = malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}

void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        struct MinHeapNode *smallestNode = heap->array[smallest];
        struct MinHeapNode *idxNode = heap->array[idx];

        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;

        swapNodes(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

int isInMinHeap(struct MinHeap* heap, int v) {
    return heap->pos[v] < heap->size;
}

struct MinHeapNode* extractMin(struct MinHeap* heap) {
    struct MinHeapNode* root = heap->array[0];
    struct MinHeapNode* lastNode = heap->array[heap->size - 1];

    heap->array[0] = lastNode;

    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int dist) {
    int i = heap->pos[v];
    heap->array[i]->dist = dist;

    while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist) {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;

        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstraHeap(int **graph, int V, int src) {
    int dist[V];

    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        heap->array[v] = newNode(v, dist[v]);
        heap->pos[v] = v;
    }

    dist[src] = 0;
    heap->array[src] = newNode(src, 0);
    heap->pos[src] = src;
    heap->size = V;

    while (heap->size) {
        struct MinHeapNode* minNode = extractMin(heap);
        int u = minNode->v;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && isInMinHeap(heap, v) &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                decreaseKey(heap, v, dist[v]);
            }
        }
    }

    printf("\nDijkstra Using Min Heap:\n");
    for (int i = 0; i < V; i++)
        printf("Distance from %d to %d = %d\n", src, i, dist[i]);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int **graph = malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
        graph[i] = calloc(V, sizeof(int));

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int start;
    printf("Enter source vertex: ");
    scanf("%d", &start);

    clock_t t1 = clock();
    dijkstraArray(graph, V, start);
    t1 = clock() - t1;

    clock_t t2 = clock();
    dijkstraHeap(graph, V, start);
    t2 = clock() - t2;

    printf("\nArray Version Time: %.6f ms", ((double)t1 * 1000) / CLOCKS_PER_SEC);
    printf("\nMin-Heap Version Time: %.6f ms\n", ((double)t2 * 1000) / CLOCKS_PER_SEC);

    return 0;
}
