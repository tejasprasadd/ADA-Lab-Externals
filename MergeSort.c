#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int left[n1];
    int right[n2];
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[beg + i];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
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
    mergesort(arr, 0, n - 1);
    end = clock();
    double cpu_time;
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time taken to sort %d elements is: %f", n, cpu_time);
    return 0;
}