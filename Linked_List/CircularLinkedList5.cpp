// Deleting First Node of Circular Singly and Doubly Linked List 
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node_1{
int data;
struct node_1*link;
};

struct node_2{
int data;
struct node_2*prev;
struct node_2*next;
};


struct node_1*add_to_empty1(int);
struct node_1*add_at_end1(struct node_1*,int);
void print(struct node_1*);
struct node_1*del_node1(struct node_1*);

struct node_2*add_to_empty2(int);
struct node_2*add_at_end2(struct node_2*,int);
void print2(struct node_2*);
struct node_2*del_node2(struct node_2*);
int main(){
struct node_1*tail_1;
struct node_2*tail_2;
tail_1=add_to_empty1(100);
tail_1=add_at_end1(tail_1,200);
print(tail_1);
cout<<"\n ";
tail_1=del_node1(tail_1);
print(tail_1);
cout<<"\n ";
tail_2=add_to_empty2(1000);
tail_2=add_at_end2(tail_2,1100);
print2(tail_2);
cout<<"\n ";
tail_2=del_node2(tail_2);
print2(tail_2);
    return 0;
}

struct node_1*add_to_empty1(int data){
struct node_1*newp=(struct node_1*)malloc(sizeof(struct node_1));
newp->data=data;
newp->link=newp;
return newp;
}

struct node_1*add_at_end1(struct node_1*tail_1,int data){
struct node_1*p=(struct node_1*)malloc(sizeof(struct node_1));
p->data=data;
p->link=tail_1->link;
tail_1->link=p;
tail_1=p;
return tail_1;
}
struct node_1*del_node1(struct node_1*tail_1){
struct node_1*temp=tail_1->link;
tail_1->link=temp->link;
free(temp);
temp=NULL;
return tail_1;
}

void print(struct node_1*tail_1){
struct node_1*p=tail_1->link;
do{
cout<<p->data<<" ";
p=p->link;
}while(p!=tail_1->link);
}

 struct node_2*add_to_empty2(int data){
 struct node_2*p=(struct node_2*)malloc(sizeof(struct node_2));
 p->data=data;
 p->prev=p;
 p->next=p;
 return p;
 }
 
 
 struct node_2*add_at_end2(struct node_2*tail_2,int data){
struct node_2*p=(struct node_2*)malloc(sizeof(struct node_2));
p->data=data;
p->next=tail_2->next;
p->prev=tail_2;
tail_2->next=p;
tail_2=p;
return tail_2;
 }

struct node_2*del_node2(struct node_2*tail_2){
struct node_2*temp=tail_2->next;
struct node_2*p;
tail_2->next=temp->next;
p=temp->next;
p->prev=tail_2;
free(temp);
temp=NULL;
return tail_2;
}


void print2(struct node_2*tail_2){
struct node_2*p=tail_2->next;
do
{
    cout<<p->data<<" ";
    p=p->next;
}while (p!=tail_2->next);

 }
 