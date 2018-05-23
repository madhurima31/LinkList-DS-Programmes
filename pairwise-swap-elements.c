#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node
{
    int data;
    struct Node *next;
};

void pairWiseSwap(struct Node **head)
{
    struct Node *prev=*head, *curr=(*head)->next;
    struct Node *next;
    *head=curr;

    if(*head==NULL || (*head)->next==NULL){
        return;
    }
    while(true){
        next=curr->next;
        curr->next=prev;

        if(next==NULL || next->next==NULL){
            prev->next=next;
            break;
        }
        prev->next=next->next;
        prev = next;
        curr=prev->next;
    }

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
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}


int main()
{
    struct Node *start = NULL;

    /*
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before  pairWiseSwap: ");
    printList(start);

    pairWiseSwap(&start);

    printf("\n Linked list after pairWiseSwap ");
    printList(start);

    getchar();
    return 0;
}
