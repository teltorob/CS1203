#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) (2 * (i) + 1)  // macro to calculate the index of the left child of a given node
#define RIGHT(i) (2 * (i) + 2) // macro to calculate the index of the right child of a given node

// function to swap the values at two indices in an array
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// function to move a node down the heap until the heap property is satisfied
void heapify(int *heap, int heap_size, int i)
{
    int min_index = i;
    int left = LEFT(i);
    int right = RIGHT(i);

    // find the minimum value among the node and its children
    if (left < heap_size && heap[left] < heap[min_index])
    {
        min_index = left;
    }
    if (right < heap_size && heap[right] < heap[min_index])
    {
        min_index = right;
    }

    // if the minimum value is not the current node, swap the values and heapify the child node
    if (min_index != i)
    {
        swap(heap, i, min_index);
        heapify(heap, heap_size, min_index);
    }
}

// function to build a min heap from an array
void build_min_heap(int *heap, int heap_size)
{
    // start from the last non-leaf node and heapify each node
    for (int i = heap_size / 2 - 1; i >= 0; i--)
    {
        heapify(heap, heap_size, i);
    }
}

int main(void)
{
    int array[] = {13, 21, 16, 84, 35, 26, 27};
    int heap_size = sizeof(array) / sizeof(int);

    // build the min heap from the array
    build_min_heap(array, heap_size);

    // print the min heap
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
