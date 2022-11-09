#include <stdio.h>
#include <stdlib.h>

// This function sorts the given array using selection sort in ascending order
void selectionSort(int *arr, int size)
{
    int i, j;
    int min;  // Stores the index of the minimum element
    int temp; // Used for swapping

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{
    int arr[] = {72, 7, 36, -5, 327};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    selectionSort(arr, size);

    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}