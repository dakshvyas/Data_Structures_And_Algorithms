//Creating a node of Circular Singly Linked List
//Creating a node of Circular Doubly Linked List
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node_1*Circular_Singly_Linked_List(int);
struct node_2*Circular_Doubly_Linked_List(int);
struct node_1{
int data;
struct node_1*link;
};
struct node_2{
struct node_2 *prev;
int data;
struct node_2*next;
};

int main(){
struct node_1*tail_1;
struct node_2*tail_2;
int data=34;
tail_1=Circular_Singly_Linked_List(data);
tail_2=Circular_Doubly_Linked_List(data);
cout<<tail_1->data;
cout<<tail_2->data;
    return 0;
}

struct node_1*Circular_Singly_Linked_List(int data){
struct node_1*temp=(struct node_1*)malloc(sizeof(struct node_1));
temp->data=data;
temp->link=temp;
return temp;
}
struct node_2*Circular_Doubly_Linked_List(int data){
struct node_2*temp=(struct node_2*)malloc(sizeof(struct node_2));
temp->data=data;
temp->prev=temp;
temp->next=temp;
return temp;
}
