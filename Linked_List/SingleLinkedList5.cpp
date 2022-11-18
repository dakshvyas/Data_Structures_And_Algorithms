//Deleting the first node
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node {
int i;
struct node*link;
};
struct node* del_f(struct node*);
void del_l(struct node*);
int main(){
struct node*head;
head=(struct node*)malloc(sizeof(struct node));
head->i=65;
head->link=NULL;

struct node*ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=75;
ptr->link=NULL;
head->link=ptr;

ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=85;
ptr->link=NULL;
head->link->link=ptr;

ptr=head;
while(ptr!=NULL){
    printf("%d ",ptr->i);
    ptr=ptr->link;
}
head=del_f(head);
ptr=head;
while(ptr!=NULL){
    printf("%d ",ptr->i);
    ptr=ptr->link;
}
//Deleting the last node
del_l(head);
ptr=head;
while(ptr!=NULL){
    printf("%d ",ptr->i);
    ptr=ptr->link;
}
return 0;
}

struct node* del_f(struct node*head){
head=head->link;
return head;
}


void del_l(struct node*head){
if(head==NULL){
    cout<<"List is empty";

}
else if(head->link==NULL){
    free(head);
    head=NULL;
}

else{
    struct node*temp1;
    struct node*temp2;
    temp1=head;
    temp2=head;
while(temp1->link!=NULL){
temp2=temp1;
temp1=temp1->link;
}
temp2->link=NULL;
free(temp1);
temp1=NULL;
}
}