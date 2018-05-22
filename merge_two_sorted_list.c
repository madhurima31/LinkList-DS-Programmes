#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
   struct Node* next;
};
struct Node* SortedMerge(struct Node* head1,struct   Node* head2)
{
    // Your Code Here
    struct Node *mergelist , *temp;
    if(!head1 || !head2){
        return (!head1)?head2:head1;
    }
    if(head1->data <=head2->data){
        mergelist=head1;
        head1=head1->next;
    }
    else{
        mergelist=head2;
        head2=head2->next;
    }
    temp=mergelist;
    while(head1 &&head2){
        if(head1->data<=head2->data){
            temp->next = head1;
            temp=temp->next;
            head1=head1->next;
        }
        else{
            temp->next = head2;
            temp=temp->next;
            head2=head2->next;
        }
    }

    if(!head1){
        temp->next=head2;
    }
    else
    {temp->next=head1;}
    return mergelist;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));


    new_node->data  = new_data;


    new_node->next = (*head_ref);


    (*head_ref)    = new_node;
}


void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{

    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;

  // a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);

    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);

    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}
