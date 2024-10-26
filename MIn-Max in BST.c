#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};
int Findmin(struct node* root) {
    if (root == NULL) return -1;  

    while (root->left != NULL) {
        root = root->left;
    }
    
    return root->data;  
    
}

int Findmax(struct node* root){
    if (root == NULL) return -1;  

    while (root->right != NULL) {
        root = root->right;
    }
    
    return root->data;  
    
}
    

