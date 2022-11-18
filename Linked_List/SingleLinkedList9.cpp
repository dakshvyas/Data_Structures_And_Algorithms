//Reverse of Single Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
int i;
struct node*link;
};
struct node * Reverse_list(struct node*);
int main(){
struct node*head;
head=(struct node*)malloc(sizeof(struct node));
head->i=55;
head->link=NULL;
struct node *ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=65;
ptr->link=NULL;
head->link=ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=75;
ptr->link=NULL;
head->link->link=ptr;
head=Reverse_list(head);
ptr=head;
while(ptr!=NULL){
    cout<<ptr->i<<" ";
    ptr=ptr->link;
}
    return 0;
}
struct node * Reverse_list(struct node*head){
struct node *prev=NULL;
struct node *next=NULL;
while(head!=NULL){
    next=head->link;
    head->link=prev;
    prev=head;
    head=next;
}
head=prev;
return head;
}