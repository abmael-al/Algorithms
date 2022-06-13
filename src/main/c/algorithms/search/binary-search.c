
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* search(Node* root, int value) {
    if(root == NULL) {
        return NULL;
    }

    while(root) {
        if(value == root->data) {
            return root;
        }

        if(value <= root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
}