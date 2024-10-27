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

void DFS(struct node* root){
    if(root==NULL) return;

    int stack[100],top=0;
    stack[top++]=root;
    while(top>0){
        struct node* current=stack[--top];
        printf("%d ",current->data);
        if(current->right != NULL)
            stack[top++] = current->right;
        if(current->left != NULL)
            stack[top++] = current->left;

    }

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

    printf("\n\n");

    printf("DFS:\n");
    DFS(root);

    printf("\n");

    return 0;
}
