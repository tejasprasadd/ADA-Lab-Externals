#include <stdio.h>
void dijkstra(int c[10][10], int n, int s, int d[10])
{
    int min, i, j, u, visited[10];
    for (i = 1; i <= n; i++)
    {
        d[i] = c[s][i];
        visited[i] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        min = 999;
        for (j = 1; j <= n; j++)

            if (d[j] < min && visited[j] == 0)
            {
                min = d[j];
                u = j;
            }
        visited[u] = 1;
        for (j = 1; j <= n; j++)
            if (visited[j] == 0 && d[j] > (d[u] + c[u][j]))
                d[j] = (d[u] + c[u][j]);
    }
}
int main()
{
    int c[10][10], n, i, j, s, d[10];
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    printf("Enter the source vertex:\n");
    scanf("%d", &s);
    dijkstra(c, n, s, d);
    for (i = 1; i <= n; i++)

        printf("Shortest distance from %d to %d is: %d\n", s, i, d[i]);
    return 0;
}