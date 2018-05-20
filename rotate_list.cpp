#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node *next;
};

void rotate_list(struct node **head, int k)
{
    struct node *curr = *head;
    for(int i=1;i<k&&curr!=NULL;i++){
        curr=curr->next;
    }
    if(curr==NULL){
        return;
    }
    struct node *kthnode = curr;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=*head;
    *head = kthnode->next;
    kthnode->next=NULL;
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
    cout<<"enter k value";
    cin>>k;
    for(int i=n-1;i>=0;i--){
        insertnode(&head,arr[i]);
    }
    cout<<"list before rotation";
    print_list(head);

    rotate_list(&head,k);
     cout<<endl<<"list after rotation";
    print_list(head);

    return 0;

}
