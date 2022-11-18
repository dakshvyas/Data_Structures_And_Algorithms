//Reverse a Singly Linked List
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *link;

//Constructor
Node(int data){
    this->data=data;
    this->link=NULL;
}
~Node(){
int value=this->data;
if(this->link!=NULL){
    delete link;
    this->link=NULL;
}
cout<<" value freed is "<<value;
}
};

void add_at_Beg(Node *&head,int data){
Node *ptr=new Node(data);
ptr->link=head;
head=ptr;
}
void add_at_end(Node * &tail,int data){
Node *ptr=new Node(data);
tail->link=ptr;
tail=tail->link;
}

void add_at_mid(Node * &head,Node *&tail,int data,int pos){
    if(pos==1){
        add_at_Beg(head,data);
        return ;
    }
int cnt=2;
Node *ptr=head;
while(pos>cnt){
ptr=ptr->link;
cnt++;
}
if(ptr->link==NULL){
    add_at_end(tail,data);
    return;
}
//Creating a new node
Node * create_Node=new Node(data);
create_Node->link=ptr->link;
ptr->link=create_Node;

}
void Revere_Linked_List(Node*&head,Node*&tail){

Node *prev=NULL;
Node*curr =head;
while(curr!=NULL){
Node*forward=curr->link;
curr->link=prev;
prev=curr;
curr=forward;
}
tail=head;
head=prev;
}


void print_Linked_List(Node *&head){
Node *p=head;
while(p!=NULL){
    cout<<p->data<<" ";
    p=p->link;
}
}

int main(){
 Node *node1=new Node(10);
Node * head=node1;
Node * tail=node1;
add_at_end(tail,30);
add_at_Beg(head,20);
add_at_mid(head,tail,55,2);
print_Linked_List(head);
cout<<"\n";
Revere_Linked_List(head,tail);
print_Linked_List(head);
cout<<endl;
cout<<head->data<<" ";
cout<<tail->data<<" ";
    return 0;
}