//Deleting last node using single pointer
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace  std;
struct node{
int i;
struct node * link;
};
void del_using_pointer(struct node*);
int main(){
struct node*head;
struct node*ptr;
head=(struct node*)malloc(sizeof(struct node));
ptr=(struct node*)malloc(sizeof(struct node));
head->i=65;
head->link=NULL;
ptr->i=55;
ptr->link=NULL;
head->link=ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=45;
ptr->link=NULL;
head->link->link=ptr;
ptr=head;
while(ptr!=NULL){
    printf("%d ",ptr->i);
    ptr=ptr->link;
}
del_using_pointer(head);
    return 0;
}
void del_using_pointer(struct node*head){
if(head==NULL){
    cout<<"List is empty";
}
else if(head->link==NULL){
free(head);
head=NULL;
}
else{
 struct node *temp=head;   
while(head->link->link!=NULL){
    temp=temp->link;
}
free(temp->link);
temp->link=NULL;
 struct node *abcd=head;
 while(abcd!=NULL){
    printf("%d ",abcd->i);
    abcd=abcd->link;
}

}
}