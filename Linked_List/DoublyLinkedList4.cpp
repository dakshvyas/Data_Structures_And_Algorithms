//Deleting First node
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
struct node*prev;
int data;
struct node*next;
};
struct node* add_to_empty(struct node*,int);
struct node*add_to_end(struct node*,int);
int main(){
struct node *head;
struct node*ptr=head;
head=add_to_empty(head,100);
head=add_to_end(head,200);
head=head->next;
free(head->prev);
head->prev=NULL; 
ptr=head;
    return 0;
}
struct node* add_to_empty(struct node*head,int data){
   struct node*temp;
   temp->prev=NULL;
   temp->next=NULL;
   temp->data=data;
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