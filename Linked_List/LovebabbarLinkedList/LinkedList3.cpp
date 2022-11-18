//Circular Single Linked List
#include<iostream>
using namespace std;


class Node{
public:
int data;
Node * next;

Node(int data){
    this->data=data;
    this->next=NULL;
}
~Node(){
int val=this->data;
    if(next!=NULL){
        delete next;
        next=NULL;
    }
    cout<<"\nMemory freed data is->"<<val;
}

};



void create_Node(Node *&tail,int data,int element){
if(tail==NULL){
Node * temp=new Node(data);
tail=temp;
temp->next=temp;
}
else{
Node * curr=tail;
while (curr->data!=element)
{
   curr=curr->next;
}
Node *temp=new Node(data);
temp->next=curr->next;
curr->next=temp;
}

}

void print(Node * tail){
    Node *ptr=tail;
    do {
  cout<<tail->data<<" ";
   tail=tail->next;
    }while(tail!=ptr) ;
}


int main(){
Node * tail=NULL;
create_Node(tail,15,3);
create_Node(tail,25,15);
create_Node(tail,35,25);
create_Node(tail,12,15);
print(tail);
    return 0;
}


