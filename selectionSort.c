#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n; i++)
    {
        min_idx = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
            swap(&arr[i], &arr[min_idx]);
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    srand(time(NULL));
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
    clock_t start, end;
    start = clock();
    selectionSort(arr, n);
    end = clock();
    double cpu_time;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time taken to sort %d elements is: %f", n, cpu_time);
    return 0;
}