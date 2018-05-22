#include<stdio.h>
#include<stdlib.h>

struct Node{
int data ;
struct Node *next;
};

int getcount(struct Node *head)
{
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;

}

int intersection(struct Node *head1, struct Node *head2)
{
    int l1 = getcount(head1);
    int l2 = getcount(head2);
    int i,diff;
    struct Node *temp1=head1,*temp2=head2;
    if(l1>l2){diff = l1-l2 ;}
    if(l2>l1){diff = l2-l1 ;}


    if(l1>l2){
            for( i=0;i<diff;i++){
                    if(temp1==NULL){
                        return -1;
                    }
                temp1=temp1->next;
            }
    }
    else{
            for( i=0;i<diff;i++){
                temp2=temp2->next;
            }
    }

    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }

}

void printlist(struct Node *ptr)
{

    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;

    }
    printf("NULL\n");

}

int main()
{
    /*
    Create two linked lists

    1st 3->6->9->15->30
    2nd 10->15->30

    15 is the intersection point
  */
   struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;

  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

    printf("intersection = %d",intersection(head1,head2));

    return 0;
}


