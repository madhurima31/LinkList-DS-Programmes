#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
//Recursive function;
/*struct node *reverse (struct node *head, int k)
{
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;


    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next !=  NULL)
       head->next = reverse(next, k);

    return prev;
}
*/

struct node* reverse_ingroups(struct node *head,int k)
{
    struct node* curr=head;
    struct node* prev=NULL;
    struct node* nextptr =NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count ++;
    }
    if(nextptr!=NULL){
        head->next=reverse_ingroups(nextptr,k);
    }
    return prev;
}



void insertnode(struct node **head,int newdata)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=newdata;
    new_node->next=*head;
    *head=new_node;
}
void print_list(struct node *ptr)
{
    while(ptr!=NULL){
        cout<<ptr->data;
        ptr=ptr->next;
    }

}

int main()
{
    struct node *head=NULL;
    int n,k;
    cout<<"enter number of elements in linklist";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter group value k ";
    cin>>k;
    for(int i=n-1;i>=0;i--){
        insertnode(&head,arr[i]);
    }
    cout<<"list before reversing in group of k";
    print_list(head);

    head = reverse_ingroups(head,k);
     cout<<endl<<"list after reversing in group of k";
    print_list(head);

    return 0;

}

