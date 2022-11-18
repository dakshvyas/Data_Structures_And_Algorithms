//Creating Node for Doubly Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
int data;
struct node*prev;
struct node*next;
};
struct node*add_at_end(struct node*);
int main(){
struct node*head;
head=(struct node *)malloc(sizeof(struct node));
head->prev=NULL;
head->data=100;
head->next=NULL;
struct node* ptr=(struct node *)malloc(sizeof(struct node));
ptr->prev=NULL;
ptr->data=200;
ptr->next=NULL;
ptr->next=head;
head=ptr;
head=add_at_end(head);
return 0;
}

struct node*add_at_end(struct node*head){
struct node*ptr,*temp;
ptr=(struct node *)malloc(sizeof(struct node));
ptr->data=300;
ptr->prev=NULL;
ptr->next=NULL;
temp=head;
while(temp!=NULL){
    temp=temp->next;
}
temp->next=ptr;
ptr->prev=temp;
ptr=head;
while(ptr!=NULL){
cout<<ptr->data<<" ";
ptr=ptr->next;
}
return head;

}