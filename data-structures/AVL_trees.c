#include <stdio.h>
#include <stdlib.h>

typedef struct AvlNode
{
    int key;
    int height;
    struct AvlNode *left;
    struct AvlNode *right;
} AvlNode;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int get_height(AvlNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int get_balance_factor(AvlNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return get_height(node->left) - get_height(node->right);
}

AvlNode *create_node(int key)
{
    AvlNode *node = (AvlNode *)malloc(sizeof(AvlNode));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

AvlNode *right_rotate(AvlNode *y)
{
    AvlNode *x = y->left;
    AvlNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;

    // Return new root
    return x;
}

AvlNode *left_rotate(AvlNode *x)
{
    AvlNode *y = x->right;
    AvlNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;

    // Return new root
    return y;
}

AvlNode *insert(AvlNode *node, int key)
{
    // Perform normal BST insertion
    if (node == NULL)
    {
        return create_node(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        // Key already exists, do nothing
        return node;
    }

    // Update height of this ancestor node
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    // Get the balance factor to check if this node became unbalanced
    int balance = get_balance_factor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        return right_rotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        return left_rotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

void pre_order(AvlNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        pre_order(root->left);
        pre_order(root->right);
    }
}

int main()
{
    AvlNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Pre order traversal of the constructed AVL tree is \n");
    pre_order(root);

    return 0;
}
