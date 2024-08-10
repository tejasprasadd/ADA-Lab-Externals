// This code works in online GDB some header file issue here prolly
// This code works in online GDB some header file issue here prolly
// This code works in online GDB some header file issue here prolly
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (pivot > arr[j])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
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
    quickSort(arr, 0, n - 1);
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
// This code works in online GDB some header file issue here prolly
// This code works in online GDB some header file issue here prolly
// This code works in online GDB some header file issue here prolly
// This code works in online GDB some header file issue here prolly
// This code works in online GDB some header file issue here prolly
