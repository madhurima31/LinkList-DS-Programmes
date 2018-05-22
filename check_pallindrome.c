#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
};
void insertfront(struct node **head,int newdata)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=newdata;
    new_node->next=(*head);
    (*head)=new_node;
}
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
bool comparelist(struct node *head1, struct node *head2)
{
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1 && temp2){
        if(temp1->data==temp2->data){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else return 0;
    }
    if(temp1==NULL && temp2==NULL){
        return 1;
    }
    return 0;
}

void printlist(struct node *ptr)
{

    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;

    }
    printf("NULL\n");

}

bool is_pallindrome(struct node *head)
{
    struct node *fastptr=head , *slowptr=head,*prev_of_slowptr=head;
    struct node *secondhalf, *midnode=NULL;
    bool result=true;


    if(head!=NULL && head->next!=NULL)
    {
        while(fastptr!=NULL && fastptr->next!=NULL){
            fastptr=fastptr->next->next;
            prev_of_slowptr=slowptr;
            slowptr=slowptr->next;
        }


        //in case of old number of nodes, fastptr!=NULL
        if(fastptr!=NULL){
            midnode=slowptr;
            slowptr=slowptr->next;
        }

       secondhalf=slowptr;
       prev_of_slowptr->next=NULL;
       reverselist(&secondhalf);

       result = comparelist(head,secondhalf);
       reverselist(&secondhalf);


       if(midnode!=NULL)//in case of odd
       {
           prev_of_slowptr->next=midnode;
           midnode->next=secondhalf;
       }
       else{
        prev_of_slowptr->next=secondhalf;
       }
    }
 return result;
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
    bool res = is_pallindrome(head);

    is_pallindrome(head)? printf("\nyes pallindrome"): printf("\nnot pallindrome");



    return 0;
}


