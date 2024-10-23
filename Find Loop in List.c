#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int FindLoop(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}
