#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void middlenode(struct node *head)
{
    struct node *fastptr=head;
    struct node *slowptr=head;
    if(head!=NULL){
        while(fastptr!=NULL && fastptr->next!=NULL){
            fastptr=fastptr->next->next;
            slowptr=slowptr->next;
        }
        printf("middle element is %d\n",slowptr->data);
    }
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
     printlist(head);
     middlenode(head);
    return 0;
}
