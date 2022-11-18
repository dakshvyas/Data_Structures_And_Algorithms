//Traversing single linked list
//Printing and counting the data
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
int i;
string Name;
struct node *link;
};
void count_nodes(struct node *);
void print_nodes(struct node *);
int main(){
    struct  node *head;
    head=(struct node*) malloc(sizeof(struct node));
    head->i=65;
    head->link=NULL;
    head->Name="Daksh vyas";
   
    struct node *ptr;
    ptr=(struct node*) malloc(sizeof(struct node));
    ptr->i=75;
    ptr->Name="AJIT";
    ptr->link=NULL;
    head->link=ptr;

    ptr=(struct node*) malloc(sizeof(struct node));
    ptr->i=85;
    ptr->Name="Prashant ";
    ptr->link=NULL;
    head->link->link=ptr;
    //Count the number of nodes
    count_nodes(head);
   //Printing the nodes
    print_nodes(head);
    return 0;
}
void count_nodes(struct node * head){
    int count =0;
    if(head==NULL){
        cout<<"Linked list is empty";
    }
    struct node* ptr=NULL;
    ptr=head;
    while (ptr!=NULL)
    { 
        count++;
        ptr=ptr->link;
    }
    printf("No of nodes: %d",count);

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