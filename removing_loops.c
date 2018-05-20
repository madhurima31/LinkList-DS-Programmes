#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

void remove_loop(struct node *head)
{
    struct node* slowptr=head;
    struct node* fastptr=head;
    while(slowptr && fastptr && fastptr->next){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr){
            printf("loop found\n");

            for(slowptr=head;slowptr->next!=fastptr->next;slowptr=slowptr->next,fastptr=fastptr->next);

            fastptr->next=NULL;
            return;

        }
    }
    printf("loop not found\n");

}

void insertnode(struct node** head,int newdata )
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data = newdata;
    new_node->next=*head;
    *head=new_node;
}

void create_loop(struct node **head, int k)
{

    struct node* ptr=*head;
    struct node* loop_pos=NULL;
    int count =1;
    while(count<k && ptr!=NULL ){
        ptr=ptr->next;
        count++;
        loop_pos=ptr;
    }


    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=loop_pos;

}

void printlist(struct node* ptr){
    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    int i,n,k;
    int result;
    struct node *head = NULL;
    printf("no of elements in the linklist");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements of list");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=n-1;i>=0;i--){
        insertnode(&head,arr[i]);
    }
    printf("enter loop position");
    scanf("%d",&k);


    create_loop(&head,k);
    remove_loop(head);
    printf("linklist after removal of loop: ");
    printlist(head);

    return 0;


}
