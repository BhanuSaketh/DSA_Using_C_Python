void zigzagTraversal(struct node* root) {
    if (root == NULL) return;  

   
    struct node* queue[100];
    int front = 0, rear = 0;  

   
    queue[rear++] = root;

    int lefttoright = 1; 

    while (rear > front) {
        int nodeCount = rear - front; 

        
        for (int i = 0; i < nodeCount; i++) {
            struct node* current = queue[front++]; 

            printf("%d ", current->data);

            // Enqueue children based on the traversal direction
            if (lefttoright) {
                if (current->left) queue[rear++] = current->left;
                if (current->right) queue[rear++] = current->right;
            } else {
                if (current->right) queue[rear++] = current->right;
                if (current->left) queue[rear++] = current->left;
            }
        }

        lefttoright = !lefttoright;
    }
}
