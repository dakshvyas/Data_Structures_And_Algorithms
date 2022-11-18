//Inserting node at beginning
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
int i;
struct node* link;
};
struct node * add_element_at_beg(struct node*,int );

int main(){
struct node * head;
head=(struct node*)malloc(sizeof(struct node));
head->i=10;
head->link=NULL;
struct node * ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=20;
ptr->link=NULL;
head->link=ptr;
int data=3;
head=add_element_at_beg(head,data);
ptr=head;
while(ptr!=NULL){
    printf("%d ",ptr->i);
    ptr=ptr->link;
}

    return 0;
}
struct node * add_element_at_beg(struct node*head,int d){
struct node *ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=d;
ptr->link=NULL;
ptr->link=head;
head=ptr;
return head;

}