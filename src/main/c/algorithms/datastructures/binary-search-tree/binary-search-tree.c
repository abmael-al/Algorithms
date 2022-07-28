#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../queue/queue-generic/Queue.h"

#define ERR_EMPTY_TREE -1
#define ERR_VALUE_DOES_NOT_EXIST_IN_THE_TREE -2

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

Node * findMin(Node* root) {
    if(isEmpty(root)) {
        return NULL;
    }

    Node *current = root;

    while(current->left) {
        current = current->left;
    }

    return current;
}

Node * findMax(Node *root) {
    if(isEmpty(root)) {
        return NULL;
    }

    Node *current = root;

    while(current->right) {
        current = current->right;
    }

    return current;
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

bool hasChild(const Node *root) {
    return root->left != NULL || root->right != NULL;
}

bool hasOneChild(const Node *root) {
    return (root->left != NULL && root->right == NULL)
        || (root->right != NULL && root->left == NULL); 
}

bool hasTwoChildren(const Node *root) {
    return root->left != NULL && root->right != NULL;
}

bool isLeaf(const Node *root) {
    return !hasChild(root);
}

Node * delete(const int value, Node *root) {
    if(isEmpty(root)) {
        return NULL;
    }

    else if(value < root->value) {
        root->left = delete(value, root->left);
    }

    else if(value > root->value) {
        root->right = delete(value, root->right);
    }

    else {
        if(isLeaf(root)) {
            free(root);
            
            root = NULL;
        }

        /* Has one child */
        else if(isEmpty(root->left)) {
            Node *temp = root;
            root = root->right;

            free(temp);
        }

        /* Has one child */
        else if(isEmpty(root->right)) {
            Node *temp = root;
            root = root->left;

            free(temp);
        }

        else if(hasTwoChildren(root)) {
            Node *minAtRightSubtree = findMin(root->right);

            root->value = minAtRightSubtree->value;
            root->right = delete(minAtRightSubtree->value, root->right);            
        }
    }

    return root;
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

bool isBinarySearchTreeUtil(Node *root, const int min, const int max) {
    if(isEmpty(root)) {
        return true;
    }
    
    if(root->value >= min && root->value <= max
     && isBinarySearchTreeUtil(root->left, min, root->value)
     && isBinarySearchTreeUtil(root->right, root->value, max)) {
        return true;
    }

    return false;
}

bool isBinarySearchTree(Node *root) {
    return isBinarySearchTreeUtil(root, INT_MIN, INT_MAX);
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
void levelOrderTraversal(Node *root) {
    if(isEmpty(root)) {
        return;
    }

    Node *current;
    Queue queue;
    
    Queue_Init(&queue, sizeof (Node *));
    enqueue(&queue, &root);
        
    while(!Queue_IsEmpty(queue)) {
        Queue_Peek(queue, &current);

        printf("%d ", current->value);

        if(!isEmpty(current->left)) {
            enqueue(&queue, &current->left);
        }

        if(!isEmpty(current->right)) {
            enqueue(&queue, &current->right);
        }

        dequeue(&queue, NULL);
    }
}

int inorderSuccessor(const int value, Node *root) {
    Node *current = search(root, value);
    Node *successor = NULL;
    Node *ancestor = root;

    if(isEmpty(current)) {
        return ERR_VALUE_DOES_NOT_EXIST_IN_THE_TREE;
    }

    if(!isEmpty(current->right)) {
        successor = findMin(current->right);

        return successor->value;
    }

    while(ancestor != current) {
        if(value < ancestor->value) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else {
            ancestor = ancestor->right;
        }
    }

    return successor->value;   
}

int main() {
    Node *root = NULL;

    int arr[] =
            { 54, 6, 1, 16, 24, 4, 12, 8,
              98, 81, 11, 7, 3, 12, 5, 9 };

    int i;
    for(i = 0; i < 16; i++) {
        insert(arr[i], &root);
    }

    printf("\n Preorder traversal: ");
    preorderTraversal(root);
    printf("\n Inorder traversal: ");
    inorderTraversal(root);
    printf("\n Postorder traversal: ");
    postorderTraversal(root);
    printf("\n Levelorder travesal: ");
    levelOrderTraversal(root);

    printf("\n Height: %d", findHeight(root));
    printf("\n Min: %d", findMin(root)->value);
    printf("\n Max: %d", findMax(root)->value);
    printf("\n Inorder successor of 6: %d", inorderSuccessor(6, root));

    root = delete(54, root);
    printf("\n Root: %d \n", root->value);

    return 0;
}