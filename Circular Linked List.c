#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* create(int n,struct node* head){
  
   struct node* root=(struct node*)malloc(sizeof(struct node));
    for(int i=0;i<n;i++){
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data:");
        scanf("%d",&temp->data);
        if(head==NULL){
            head=temp;
            root=head;
        }
        else{
            head->next=temp;
            head=head->next;
        }
    }
    head=root;
    return root;
}
void display(struct node* head){
    struct node* temp=head;
    printf("Data: %d\n",temp->data);
    temp=temp->next;
    while(temp!=head){
        printf("Data: %d\n",temp->data);
        temp=temp->next;
    }
}
int main()
{
    struct node* head=NULL;
    int n;
    printf("Enter Number of Nodes:");
    scanf("%d",&n);
    head=create(n,head);
    display(head);
    return 0;
}
