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


struct node* createTreeFromArray(int arr[], int n, int i) {
    if (i >= n) return NULL;

    struct node* root = createNode(arr[i]);
    root->left = createTreeFromArray(arr, n, 2 * i + 1); // Left child
    root->right = createTreeFromArray(arr, n, 2 * i + 2); // Right child

    return root;
}


void inorder(struct node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root==NULL) return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = createTreeFromArray(arr, n, 0);

    printf("Inorder Traversal: \n");
    inorder(root);

    printf("\n");

    printf("Preorder Traversal: \n");
    preorder(root);

    printf("\n");

    printf("Postorder Traversal: \n");
    postorder(root);

    printf("\n");

    return 0;
}
