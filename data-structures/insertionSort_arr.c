#include <stdio.h>
#include <stdlib.h>

// This function will sort the given array using insertion sort in ascending order
void insertionSort(int *arr, int size)
{
    int i, j;
    int pivot;

    for (i = 1; i < size; i++)
    {
        pivot = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > pivot)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = pivot;
    }
}

int main()
{
    int arr[] = {72, 7, 36, -5, 327};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    insertionSort(arr, size);

    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}