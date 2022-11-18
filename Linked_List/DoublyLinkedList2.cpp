//Doubly Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
struct node*prev;
int data;
struct node*next;
};
struct node*add_empty_node(struct node*,int );
struct node*add_at_beg(struct node*,int );
struct node*add_at_end(struct node*,int );
struct node*add_after_pos(struct node*,int ,int );

int main(){
struct node *head;
struct node*ptr;
head=add_empty_node(head,100);
head=add_at_beg(head,200);
head=add_at_end(head,300);
head=add_after_pos(head,2,400);
ptr=head;
while(ptr!=NULL){
    cout<<ptr->data;
    ptr=ptr->next;
}
    return 0;
}

struct node*add_empty_node(struct node*head,int data){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->prev=NULL;
temp->data=data;
temp->next=NULL;
head=temp;
return head;
}

struct node*add_at_beg(struct node*head,int data){
struct node * temp=(struct node*)malloc(sizeof(struct node));
temp->prev=NULL;
temp->next=NULL;
temp->data=data;
temp->next=head;
head=temp;
return head;
}
struct node*add_at_end(struct node*head,int data){
struct node*p;    
struct node * temp=(struct node*)malloc(sizeof(struct node));
temp->prev=NULL;
temp->next=NULL;
temp->data=data;
p=head;
while(p->next!=NULL){
    p=p->next;
}
p->next=temp;
temp->prev=p;
return head;
}
struct node*add_after_pos(struct node* head,int pos,int data){
    struct node *nList=(struct node*)malloc(sizeof(struct node));
    nList->prev=NULL;
    nList->data=data;
    nList->next=NULL;
    struct node*previous=NULL;
    struct node*nextt=head;
while(pos!=1){
    nextt=nextt->next;
    pos--;
}
if (nextt->next==NULL){
    nextt->next=nList;
    nList->prev=nextt;
}
else{
previous=nextt->next;
nextt->next=nList;
previous->prev=nList;
nList->next=previous;
nList->prev=nextt;

}
return head;
}

