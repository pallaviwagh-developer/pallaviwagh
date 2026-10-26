
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

// Depth First Search function
void DFS(int vertex)
{
    int i;

    printf("%d ", vertex);

    visited[vertex] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, edges;
    int u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}
