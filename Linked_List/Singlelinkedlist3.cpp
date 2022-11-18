//Inserting at the end
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node{
int i;
struct  node*link;
};
void print_nodes(struct node *);
void add_element_at_end(struct node*);
int main(){
    struct node*head;
    struct node*ptr;
    head=(struct node*)malloc(sizeof(struct node));
    head->i=65;
    head->link=NULL;

    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->i=75;
    ptr->link=NULL;
    head->link=ptr;
    //Inserting at the end
    add_element_at_end(head);
    print_nodes(head);
    return 0;
}
void add_element_at_end(struct node*head){
struct node *ptr,*temp;
ptr=head;
temp=(struct node*)malloc(sizeof(struct node));
temp->i=85;
temp->link=NULL;
while(ptr!=NULL){
    ptr=ptr->link;
}
ptr->link=temp;
}
void print_nodes(struct node *head){
struct node *ptr;
ptr=head;
cout<<"Nodes :";
while(ptr!=NULL){
    printf("%d",ptr->i);
    ptr=ptr->link;
}
}