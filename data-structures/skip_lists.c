#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 6

typedef struct node
{
    int key;
    struct node *forward[MAX_LEVEL];
} node;

typedef struct list
{
    node *header;
    int level;
} list;

list *create_list()
{
    list *l = (list *)malloc(sizeof(list));
    l->level = 0;
    l->header = (node *)malloc(sizeof(node));
    for (int i = 0; i < MAX_LEVEL; i++)
    {
        l->header->forward[i] = NULL;
    }
    return l;
}

node *create_node(int key, int level)
{
    node *n = (node *)malloc(sizeof(node));
    n->key = key;
    for (int i = 0; i < level; i++)
    {
        n->forward[i] = NULL;
    }
    return n;
}

int random_level()
{
    int level = 1;
    while (rand() % 2)
    {
        level++;
    }
    return (level < MAX_LEVEL) ? level : MAX_LEVEL;
}

void insert(list *l, int key)
{
    node *update[MAX_LEVEL];
    node *x = l->header;
    for (int i = l->level - 1; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->key < key)
        {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];
    if (x == NULL || x->key != key)
    {
        int level = random_level();
        if (level > l->level)
        {
            for (int i = l->level; i < level; i++)
            {
                update[i] = l->header;
            }
            l->level = level;
        }
        x = create_node(key, level);
        for (int i = 0; i < level; i++)
        {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
}

void delete(list *l, int key)
{
    node *update[MAX_LEVEL];
    node *x = l->header;
    for (int i = l->level - 1; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->key < key)
        {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];
    if (x->key == key)
    {
        for (int i = 0; i < l->level; i++)
        {
            if (update[i]->forward[i] != x)
            {
                break;
            }
            update[i]->forward[i] = x->forward[i];
        }
        free(x);
        while (l->level > 0 && l->header->forward[l->level - 1] == NULL)
        {
            l->level--;
        }
    }
}

int search(list *l, int key)
{
    node *x = l->header;
    for (int i = l->level - 1; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->key < key)
        {
            x = x->forward[i];
        }
    }
    x = x->forward[0];
    return x != NULL && x->key == key;
}

void print_list(list *l)
{
    for (int i = 0; i < l->level; i++)
    {
        node *x = l->header->forward[i];
        printf("Level %d: ", i);
        while (x != NULL)
        {
            printf("%d ", x->key);
            x = x->forward[i];
        }
        printf("\n");
    }
}

// create skip list from an array
int main()
{
    int arr[] = {3, 6, 2, 11, 9, 14, 12, 7, 13, 1, 4, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    list *l = create_list();
    for (int i = 0; i < n; i++)
    {
        insert(l, arr[i]);
    }
    print_list(l);
    delete (l, 11);
    print_list(l);
    return 0;
}
