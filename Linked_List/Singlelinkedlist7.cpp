//Deleting a node at any position

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace  std;
struct node{
int i;
struct node*link;
};
void del_pos(struct node*,int);

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
ptr=(struct node*)malloc(sizeof(struct node));
ptr->i=35;
ptr->link=NULL;
head->link->link->link=ptr;

int position=3;

del_pos(head,position);

return 0;
}
void del_pos(struct node* head,int pos){
    struct node* current=head;
    struct node* previous=head;
if (head=NULL){
    cout<<"List is empty";
}
else if(pos==1){
    head=head->link;
}
else{
    while(pos!=1){
        previous=current;
        current=current->link;
        pos--;
    }
    previous->link=current->link;
    free(current);
    current =NULL;
    cout<<"This is result"<<head->i;
struct node*hy=head;
while(hy!=NULL){
    cout<<hy->i;
    hy=hy->link;
}
}

}