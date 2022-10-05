#include <stdio.h>
#include <stdlib.h>

// Create a scruct which will act as a node in the linked list
struct node
{
    int data;
    struct node *next;
};

// A function to create the nodes
int addNodes(struct node *head, int data)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
    return 0;
}

// A function to reverse the linked list
struct node *reverseList(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// A function to print the linked list
int printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> \t", head->data);
        head = head->next;
    }
    return 0;
}

// A fucntion to half the linked list
int halfLinkedList(struct node *head)
{
    struct node *hare = head;
    struct node *tortoise = head;

    while (hare != NULL && hare->next != NULL)
    {
        hare = hare->next->next;
        tortoise = tortoise->next;

        printf("%d -> \t", tortoise->data);
    }
    return 0;
}

// A function to chunk reverse the linked list
struct node *chunkReverse(struct node *head, int k)
{
    struct node *current = head;
    struct node *next = NULL;
    struct node *prev = NULL;

    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = chunkReverse(next, k);
    }

    return prev;
}

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    while (1)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);

        if (data == -1)
        {
            break;
        }

        addNodes(head, data);
    }
    head = head->next;
    printf("The linked list is: ");
    printList(head);

    printf("\n");

    head = chunkReverse(head, 3);
    printf("The linked list after reversing is: ");
    printList(head);

    // head = reverseList(head);
    // printf("The reversed linked list is: ");
    // printList(head);
}