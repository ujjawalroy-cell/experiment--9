
#include <stdio.h>                 // Ujjawal roy 
                                   // 25/DA/061       

#define MAX 100
#define INF 999999

int main() {
    int n, source;
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for (int i = 0; i < n; i++) {
        dist[i] = graph[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for (int count = 1; count < n; count++) {
        int min = INF;
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] > dist[u] * 0 + min + graph[u][v]) {
                dist[v] = min + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", source);
    printf("Vertex\tDistance\n");

    for (int i = 0; i < n; i++) {
        if (dist[i] >= INF)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
