#include <stdio.h>
#include <stdlib.h>

// A struct to create a Binary Search Tree
struct node
{
    int data;
    struct node *next;
    struct node *prev;
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
    temp->prev = NULL;

    return temp;
}

// A funtion to insert data into the Binary Search Tree
void insertNode(struct node *head, int data)
{
    struct node *temp = genNode(data);

    if (temp != NULL)
    {
        if (head == NULL)
        {
            head = temp;
            return;
        }

        struct node *prev = NULL;
        struct node *curr = head;

        while (curr != NULL)
        {
            prev = curr;

            if (curr->data > data)
            {
                curr = curr->prev;
            }
            else
            {
                curr = curr->next;
            }
        }

        if (prev->data > data)
        {
            prev->prev = temp;
        }
        else
        {
            prev->next = temp;
        }
    }
}

struct node *deleteNode(struct node *head, int target)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->data > target)
    {
        head->prev = deleteNode(head->prev, target);
    }
    else if (head->data < target)
    {
        head->next = deleteNode(head->next, target);
    }
    else
    {
        if (head->next == NULL)
        {
            struct node *temp = head->prev;
            free(head);
            return temp;
        }

        else if (head->prev == NULL)
        {
            struct node *temp = head->next;
            free(head);
            return temp;
        }
        }
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 6;
    head->next = NULL;
    head->prev = NULL;

    insertNode(head, 5);
    insertNode(head, 10);
    insertNode(head, 1);
    insertNode(head, -5);

    printf("Root value %d\n", head->data);
    printf("1st left to root %d\n", head->prev->data);
    printf("2nd left to root %d\n", head->prev->prev->data);
    printf("3rd left to root %d\n", head->prev->prev->prev->data);
    printf("1st right to root %d\n", head->next->data);
}