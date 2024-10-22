#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* createTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    struct node* root = createNode(data);

    printf("Enter left child of %d\n", data);
    root->left = createTree();

    printf("Enter right child of %d\n", data);
    root->right = createTree();

    return root;
}

void inorder(struct node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    printf("Create the binary tree:\n");
    struct node* root = createTree();

    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal:\n");
    postorder(root);
    printf("\n");

    return 0;
}
