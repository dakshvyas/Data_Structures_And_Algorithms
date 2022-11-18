#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node{
int i;
struct node*link;
};
int main(){
    struct node*head;
    head=(struct node*)malloc(sizeof(struct node));
    head->i=65;
    head->link=NULL;
    struct node*ptr =(struct node*)malloc(sizeof(struct node));
    ptr->i=34;
    ptr->link=NULL;
    head->link=ptr;

    ptr=(struct node*)malloc(sizeof(struct node));
     ptr->i=55;
    ptr->link=NULL;
    head->link->link=ptr;
    struct node*New=(struct node*)malloc(sizeof(struct node));
    New->i=88;
    New->link=NULL;
    New->link=head->link->link;
    head->link->link=New;
    ptr=head;
     while(ptr!=NULL){
        printf("%d ",ptr->i);
        ptr=ptr->link;
     }
    
    return 0;
}