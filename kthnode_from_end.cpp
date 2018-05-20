#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

int kthnodefrom_end(struct node* head,int k)
{
    if(k<=0 || !head){
        return -1;
    }
    struct node* refptr, *kthNode;
    refptr=kthNode=head;

    for(int i=0;i<k;i++){
        //if k is>size of linklist then refptr will be NULL
        if(refptr==NULL){
            return -1;
        }
        refptr=refptr->next;
    }
    for(;refptr;refptr=refptr->next , kthNode=kthNode->next);
    return kthNode? (kthNode->data):-1;

}
void printlist(struct node* ptr)
{
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

void insertnode(struct node** head, int newdata)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data = newdata;
    new_node->next =*head;
    *head = new_node;
}

int main()
{
    struct node* head = NULL;
    insertnode(&head,5);
    insertnode(&head,4);
    insertnode(&head,3);
    insertnode(&head,2);
    insertnode(&head,1);
    printlist(head);
    printf("\n");

    int result =kthnodefrom_end(head,6);
    printf("%d",result);

}
