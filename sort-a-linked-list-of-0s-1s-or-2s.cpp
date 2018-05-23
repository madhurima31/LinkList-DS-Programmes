#include<bits/stdc++.h>

struct Node{
int data;
struct Node *next;
};

void sortList(struct Node *head)
{
    int arr[3]={0,0,0};
    struct Node *ptr =head;
    while(ptr!=NULL){
        arr[ptr->data]+=1;
        ptr=ptr->next;
    }
    int i=0;
    ptr=head;
    while(ptr!=NULL){
        if(arr[i]==0){
            i++;
        }
        else{
            ptr->data=i;
            arr[i]--;
            ptr=ptr->next;
        }
    }
}

void push (struct Node** head_ref, int new_data)
{

    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}


void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


int main(void)
{
    struct Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    printf("Linked List Before Sorting\n");
    printList(head);

    sortList(head);

    printf("Linked List After Sorting\n");
    printList(head);

    return 0;
}

