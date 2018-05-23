//delete-without-head-pointer
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void deleteNode(struct node *node_ptr)
{
    struct node *temp=node_ptr->next;
    node_ptr->data=temp->data;
    node_ptr->next=temp->next;
    free(temp);

}

void push(struct node **head,int newdata)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=newdata;
    new_node->next=(*head);
    (*head)=new_node;
}

void printlist(struct node *ptr)
{

    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;

    }
    printf("NULL\n");

}

int main()
{
  struct node* head = NULL;
   // 1->12->1->4->1
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    printf("Before deleting \n");
    printlist(head);
    deleteNode(head->next->next);

    printf("\nAfter deleting \n");
    printlist(head);

    return 0;
}
