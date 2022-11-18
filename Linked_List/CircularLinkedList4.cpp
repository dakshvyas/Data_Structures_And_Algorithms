// Insertion between the nodes of Circular Singly and Doubly Linked List 
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
struct node_1*add_at_beg1(struct node_1*,int);
struct node_1*add_at_end1(struct node_1*,int);
struct node_1*add_after_pos1(struct node_1*,int,int);
void print(struct node_1*);
struct node_2*add_to_empty2(int);
struct node_2*add_at_beg2(struct node_2*,int);
struct node_2*add_at_end2(struct node_2*,int);
struct node_2*add_after_pos2(struct node_2*,int,int);
void print(struct node_2*);

int main(){
struct node_1*tail_1;
struct node_2*tail_2;
tail_1=add_to_empty1(100);
tail_1=add_at_beg1(tail_1,200);
tail_1=add_at_end1(tail_1,300);
tail_1=add_after_pos1(tail_1,2,250);
print(tail_1);

tail_2=add_to_empty2(1000);
tail_2=add_at_beg2(tail_2,1100);
tail_2=add_at_end2(tail_2,1300);
tail_2=add_after_pos2(tail_2,2,1250);
print(tail_2);
    return 0;
}

struct node_1*add_to_empty1(int data){
struct node_1*newp=(struct node_1*)malloc(sizeof(struct node_1));
newp->data=data;
newp->link=newp;
return newp;
}
struct node_1*add_at_beg1(struct node_1*tail_1,int data){
struct node_1*p=(struct node_1*)malloc(sizeof(struct node_1));
p->data=data;
p->link=tail_1->link;
tail_1->link=p;
return tail_1;
}

void print(struct node_1*tail_1){
struct node_1*p=tail_1->link;
do{
cout<<p->data<<" ";
p=p->link;
}while(p!=tail_1->link);
}


struct node_1*add_at_end1(struct node_1*tail_1,int data){
struct node_1*p=(struct node_1*)malloc(sizeof(struct node_1));
p->data=data;
p->link=tail_1->link;
tail_1->link=p;
tail_1=p;
return tail_1;
}

 struct node_2*add_to_empty2(int data){
 struct node_2*p=(struct node_2*)malloc(sizeof(struct node_2));
 p->data=data;
 p->prev=p;
 p->next=p;
 return p;
 }
 struct node_2*add_at_beg2(struct node_2*tail_2,int data){
struct node_2*p=(struct node_2*)malloc(sizeof(struct node_2));
p->data=data;
p->prev=tail_2;
p->next=tail_2->next;
tail_2->next=p;
return tail_2;
 }
 void print(struct node_2*tail_2){
struct node_2*p=tail_2->next;
do
{
    cout<<p->data<<" ";
    p=p->next;
}while (p!=tail_2->next);

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

 struct node_1*add_after_pos1(struct node_1*tail_1,int pos,int data){
struct node_1*temp=tail_1->link;
struct node_1*p=add_to_empty1(data);
while(pos>1){
temp=temp->link;
pos--;
}
p->link=temp->link;
temp->link=p;
return tail_1;
 }
 struct node_2*add_after_pos2(struct node_2*tail_2,int pos,int data){
struct node_2*temp=tail_2->next;
struct node_2*newp=add_to_empty2(data);
while(pos>1){

   temp=temp->next;
   pos--; 
}
newp->next=temp->next;
newp->prev=temp;
temp->next=newp;
return tail_2;
 }