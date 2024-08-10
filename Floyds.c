// FLOYD'S ALGORITHM
#include <stdio.h>
#include <conio.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
}
void floyd(int p[][10], int n)
{
    int i, j, k;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    p[i][j] = 0;
                else
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
int main()
{
    int n, i, j, a[10][10];
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    floyd(a, n);
    printf("\nShortest path matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}