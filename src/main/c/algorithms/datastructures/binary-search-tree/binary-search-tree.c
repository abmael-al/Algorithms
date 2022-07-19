#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../queue/queue-generic/Queue.h"

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

int findMin(Node* root) {
    if(isEmpty(root)) {
        return ERR_EMPTY_TREE;
    }

    Node *current = root;

    while(current->left) {
        current = current->left;
    }

    return current->value;
}

int findMax(Node *root) {
    if(isEmpty(root)) {
        return ERR_EMPTY_TREE;
    }

    Node *current = root;

    while(current->right) {
        current = current->right;
    }

    return current->value;
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

// --- TREE TRAVERSAL: DEPTH-FIRST  ---
// Go as deep as possible down one path before  backing up 
// and trying a different one.

// Preorder traversal (root, left, right): read the data and
// go as deep as possible to the left before backing up and 
// going to the right.
void preorderTraversal(const Node *root) {
    if(root) {
        printf("%d ", root->value);

        preorderTraversal(root->left);

        preorderTraversal(root->right);
    }
}

// Inorder traversal (left, root, right): go as deep as possible 
// to the left before backing up, reading the data and going to 
// the right.
void inorderTraversal(const Node *root) {
    if(root) {
        inorderTraversal(root->left);

        printf("%d ", root->value);

        inorderTraversal(root->right);
    }
}

// Postorder traversal (left, right, root): go as deep as possible
// to the left and then go as deep as possible to the right before
// backing up and reading the data.
void postorderTraversal(const Node* root) {
    if(root) {
        postorderTraversal(root->left);

        postorderTraversal(root->right);

        printf("%d ", root->value);
    }
}

// --- TREE TRAVERSAL: BREADTH-FIRST  ---
// Visit all the nodes at the same level (depth) before visiting 
// the nodes at the next level.

int main() {
    Node *root = NULL;
    int arr[] =
            { 54, 6, 1, 16, 24, 4, 12, 8,
              98, 81, 11, 7, 3, 12, 5, 9 };

    int i;
    for(i = 0; i < 16; i++) {
        insert(arr[i], &root);
    }

    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);

    printf("\nHeight: %d", findHeight(root));
    printf("\nMin: %d", findMin(root));
    printf("\nMax: %d", findMax(root));

    return 0;
}