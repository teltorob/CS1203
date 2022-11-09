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

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> \t", head->data);
        head = head->next;
    }
}

void selectionSort(struct node *head)
{
    while (head != NULL)
    {
        struct node *curr = head;
        struct node *t = head;
        int temp = 0;
        while (curr != NULL)
        {
            if (curr->data < t->data)
                t = curr;
            curr = curr->next;
        }
        temp = head->data;
        head->data = t->data;
        t->data = temp;
        head = head->next;
    }
}

int main()
{
    int arr[] = {5, 7, 28, 13, 2, 11};
    int size = 6;

    struct node *ll = arrayToLinkedList(arr, size);
    selectionSort(ll);
    printList(ll);
}