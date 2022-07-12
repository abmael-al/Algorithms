#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERR_EMPTY_TREE -1

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node * createNode(const int value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int isEmpty(const Node *node) {
    return node == NULL;
}

void insert(const int value, Node **root) {
    Node *node = createNode(value);
    
    if(isEmpty(*root)) {
        *root = node;
        return;
    }

    Node *current = *root;
    Node *parent = NULL;

    while(1) {
        parent = current;

        if(value < parent->value) {
            current = current->left;

            if(isEmpty(current)) {
                parent->left = node;
                break;
            }
        }
        else {
            current = current->right;

            if(isEmpty(current)) {
                parent->right = node;
                break;
            }
        }
    }
}

Node * search(Node *root, const int value) {
    Node *current = root;

    while(current) {
        if(value < current->value) {
            current = current->left;
        }
        else if(value > current->value) {
            current = current->right;
        }
        else {
            return current;
        }
    }

    return NULL;
}

void inorderTraversal(const Node *root) {
    if(root) {
        inorderTraversal(root->left);

        printf("%d ", root->value);

        inorderTraversal(root->right);
    }
}

// Height: number of edges in longest path 
// from the node to a leaf node.
int findHeight(const Node *root) {
    if(isEmpty(root)) {
        return ERR_EMPTY_TREE;
    }

    int leftHeight, rightHeight;

    leftHeight = findHeight(root->left);
    rightHeight = findHeight(root->right);

    return fmax(leftHeight, rightHeight) + 1;
}
