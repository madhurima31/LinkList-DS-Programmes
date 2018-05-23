#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* newnode(int data)
{
    struct Node* node =(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
};

struct Node* addTwoLists(struct Node* first,struct Node* second)
{
    struct Node *temp,*prev=NULL, *res=NULL;
    int carry=0;
    int sum;
    while(first!=NULL || second!=NULL){
        sum= carry + (first?first->data:0) + (second?second->data:0) ;
        carry= (sum>=10)?1:0;
        sum=sum%10;
        temp= newnode(sum);

        if(res==NULL){
            res=temp;
        }
        else{
            prev->next=temp;
        }

        prev=temp;
        if(first){
            first=first->next;
        }
        if(second){
            second=second->next;
        }
    }

    if(carry>0){
        temp->next=newnode(carry);
    }
    return res;

}


void push(struct Node** head_ref, int new_data)
{

    struct Node* new_node = newnode(new_data);
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
    printf("\n");
}

int main(void)
{
    struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);

   return 0;
}
