#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

int detect_loop(struct node *head)
{
    struct node* slowptr=head;
    struct node* fastptr=head;
    while(slowptr && fastptr && fastptr->next){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr){

            return 1;
        }
    }
    return 0;
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
    result=detect_loop(head);
    if(result==0){
        printf("loop not found");
    }
    else if(result==1){
      printf("loop found");
    }

    return 0;


}
