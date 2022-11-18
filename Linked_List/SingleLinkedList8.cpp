#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
int i;
struct node*link;
};
struct node *del_linked_list(struct node *);
int main(){
struct node *head;
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
head=del_linked_list(head);
if (head==NULL){
    cout<<"Linked list is empty";
}
}

struct node *del_linked_list(struct node *head){
struct node *temp=head;
while(temp!=NULL){
temp=temp->link;
free(head);
head=temp;
}
return head;
}