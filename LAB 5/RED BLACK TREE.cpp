#include <stdio.h>
#include <stdlib.h>
typedef enum { RED, BLACK } Color;
struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
};
struct Node *root = NULL;
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}
void rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}
void rotateRight(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;

    if (x->right)
        x->right->parent = y;
    x->parent = y->parent;
    if (!y->parent)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void fixInsert(struct Node* z) {
    while (z->parent && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node* y = z->parent->parent->right;

            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        } else {
            struct Node* y = z->parent->parent->left;

            if (y && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void insert(int data) {
    struct Node* z = createNode(data);
    struct Node* y = NULL;
    struct Node* x = root;

    while (x) {
        y = x;
        if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (!y)
        root = z;
    else if (data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(z);
}
void printTree(struct Node* node, int space) {
    if (!node)
        return;
    space += 6;
    printTree(node->right, space);
    printf("\n");
    for (int i = 6; i < space; i++)
        printf(" ");
    printf("%d(%c)", node->data, node->color == RED ? 'R' : 'B');
    printTree(node->left, space);
}
int main() {
    int n, val;
    printf("Enter number of elements: ");
    see:
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(val);
    }
    printf("\nRed-Black Tree Structure:\n");
    printTree(root, 0);

    return 0;
}

