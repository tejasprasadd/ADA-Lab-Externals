// WARSHALL'S ALGORITHM
#include <stdio.h>
#include <conio.h>
void warshal(int p[][10], int n)
{
    int i, j, k;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                p[i][j] = p[i][j] || p[i][k] && p[k][j];
}
int main()
{
    int n, i, j, a[10][10], u, v;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    warshal(a, n);
    printf("\nShortest path matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}