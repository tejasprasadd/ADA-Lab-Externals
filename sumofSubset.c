#include <stdio.h>
#define max 100
void sumofSubset(int set[], int subset[], int n, int nodeCount, int sum, int total, int subSize)
{
    if (total == sum)
    {
        printf("Subset found: { ");
        for (int i = 0; i < subSize; i++)
        {
            printf("%d ", subset[i]);
        }
        printf(" }\n");
        return;
    }
    else
    {
        for (int i = nodeCount; i < n; i++)
        {
            subset[subSize] = set[i];
            sumofSubset(set, subset, n, i + 1, sum, total + set[i], subSize + 1);
        }
    }
}
int main()
{
    int set[max], subset[max], n, sum;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the sum: ");
    scanf("%d", &sum);
    sumofSubset(set, subset, n, 0, sum, 0, 0);
    return 0;
}