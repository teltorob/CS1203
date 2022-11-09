#include <stdio.h>
#include <stdlib.h>

// A struct to creaete a linked list
struct node
{
    int data;
    struct node *next;
};

// A function that creates nodes
struct node *genNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        return NULL;
    }

    temp->data = data;
    temp->next = NULL;

    return temp;
}

// A function that converts an array into a linked list
struct node *arrayToLinkedList(int *arr, int size)
{
    struct node *head = genNode(arr[0]);

    if (head == NULL)
    {
        return NULL;
    }

    struct node *curr = head;

    for (int i = 1; i < size; i++)
    {
        curr->next = genNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

// A function to return the last node of a given linked list
struct node *lastNode(struct node *head)
{
    if (head == NULL)
    {
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

// Sorting the linked list using quick sort
struct node *quickPartition(struct node *head, struct node *last)
{
    struct node *pivot = head;
    struct node *curr = head;
    int temp = 0;

    while (curr != last)
    {
        if (curr->data < last->data)
        {
            pivot = head;
            temp = pivot->data;
            head->data = curr->data;
            curr->data = temp;

            head = head->next;
        }
        curr = curr->next;
    }
    temp = last->data;
    last->data = head->data;
    head->data = temp;
    return pivot;
}
void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> \t", head->data);
        head = head->next;
    }
}

void quickSort(struct node *head, struct node *last)
{
    if (head == last)
        return;

    struct node *part = quickPartition(head, last);
    quickSort(head, part);
    quickSort(part->next, last);
}

int main()
{
    int arr[] = {5, 7, 28, 13, 2, 11}; // Initialising an array
    int size = 6;

    struct node *ll = arrayToLinkedList(arr, size);
    struct node *last = lastNode(ll);

    quickSort(ll, last); // Sorts the linked list using quicksort
    printList(ll);       // Prints the linked list
}