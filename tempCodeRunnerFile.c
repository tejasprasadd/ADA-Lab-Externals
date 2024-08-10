#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void topologicalSort(int a[MAX][MAX], int n);

int main()
{
    int i, j, n, a[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // Call the topological sort function
    topologicalSort(a, n);

    return 0;
}

void topologicalSort(int a[MAX][MAX], int n)
{
    int i, j, k, indeg[MAX], flag[MAX], count = 0;

    // Initialize indegrees and flags
    for (i = 0; i < n; i++)
    {
        flag[i] = 0;
        indeg[i] = 0;
    }

    // Calculate indegrees
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a[i][j] == 1)
                indeg[j]++;

    printf("Topological Order is : \n");

    while (count < n)
    {
        for (k = 0; k < n; k++)
        {
            if ((indeg[k] == 0) && (flag[k] == 0))
            {
                printf("%d\t", k + 1);
                flag[k] = 1;
            }
            for (i = 0; i < n; i++)
            {
                if (a[k][i] == 1)
                    indeg[i]--;
            }
        }
        count++;
    }
    printf("\n");
}
