#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* create(int n, struct node* head) {
    struct node* root = NULL;
    struct node* last = NULL;

    for (int i = 0; i < n; i++) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &temp->data);
        
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL) {
            head = temp;
            root = head;
        } else {
            last->next = temp;
            temp->prev = last;
        }
        
        last = temp;
    }

    return root;
}

void display(struct node* head) {
    struct node* temp = head;
    struct node* last;
    printf("Forward traversal:\n");
    while (temp != NULL) {
        printf("Data: %d\n", temp->data);
        last=temp;
        temp = temp->next;
    }
    
    printf("Backward traversal:\n");
    while (last != NULL) {
        printf("Data: %d\n", last->data);
        last = last->prev;
    }
}

int main() {
    struct node* head = NULL;
    int n;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);
    head = create(n, head);
    display(head);
    return 0;
}
