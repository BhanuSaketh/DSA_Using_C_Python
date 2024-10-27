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

void BFS(struct node* root){
    if(root==NULL) return;

    int queue[100],rear=0,front=0;

    queue[rear++]=root;

    while(front<rear){
        struct node* current=queue[front++];
        printf("%d ",current->data);
        if(current->left!=NULL)
            queue[rear++]=current->left;
        if(current->right!=NULL)
            queue[rear++]=current->right;
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

    printf("BFS:\n");
    BFS(root);
    
    printf("\n");

    return 0;
}
