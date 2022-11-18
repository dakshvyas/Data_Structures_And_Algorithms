//Creating a Doubly Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
struct node *prev;
int data;
struct node *next;
};
struct node *create_Full_Linked_List(struct node*);
struct node*add_to_empty(struct node*,int);
struct node*add_to_end(struct node*,int);
int main(){
  struct node*head=NULL;
  struct node*ptr;
head=create_Full_Linked_List(head);
ptr=head;
while(ptr!=NULL)
{
    cout<<ptr->data<<" ";
    ptr=ptr->next;
}

    return 0;

}
struct node *create_Full_Linked_List(struct node*head){
int data,n;
cout<<"Enter number of nodes you want to create";
cin>>n;
if(n==0){
    return head;
}
cout<<"Enter the element for node 1: ";
cin>>data;
head=add_to_empty(head,data);
for(int i=1;i<n;i++){
    cout<<"Enter the element for node "<<i+1;
    cin>>data;
    head=add_to_end(head,data);
}
return head;

}

struct node*add_to_empty(struct node*head,int data){
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->prev=NULL;
temp->data=data;
temp->next=NULL;
head=temp;
return head;
}
struct node*add_to_end(struct node*head,int data){
struct node *p;
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->prev=NULL;
temp->data=data;
temp->next=NULL;
p=head;
while(p->next!=NULL){
    p=p->next;
}
p->next=temp;
temp=p;
return head;
}