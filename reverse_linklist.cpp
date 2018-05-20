#include<stdio.h>
#include<stdlib.h>

struct node{
int data ;
struct node *next;
};

void reverselist(struct node **head)
{
    struct node *prev=NULL;
    struct node *curr=*head;
    struct node *next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head = prev;
}
void insertfront(struct node **head,int newdata)
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
    struct node *head=NULL;
    int i,data,n;
    printf("enter no of elements in linklist");
    scanf("%d", &n);
    int arr[n];
    for (i=0;i<n;i++){
        scanf("%d",& arr[i]);
    }
     for (i=n-1;i>=0;i--){
        insertfront(&head,arr[i]);
    }
    reverselist(&head);
     printlist(head);

    return 0;
}

