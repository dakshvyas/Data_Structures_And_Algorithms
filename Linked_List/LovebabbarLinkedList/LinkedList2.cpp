//Doubly Linked List
#include<iostream>
using namespace std;

class Node {
public:
int data;
Node *prev;
Node *next;

Node(int data){
this->data=data;
this->prev=NULL;
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

int get_Lenght(Node *head)
{
    int lenght=0;
    Node * temp=head;
    while(temp!=NULL){
        temp=temp->next;
         lenght++;
    }
    return lenght;
}

void add_at_Beg(Node * & head,int data){
Node *ptr=new Node(data);
ptr->next=head;
head=ptr;
}


void add_at_End(Node *&tail,int data){
Node *ptr=new Node(data);
ptr->prev=tail;
tail->next=ptr;
tail=tail->next;
}


void add_at_Mid(Node *&head,Node *&tail,int data,int pos){
int cnt=1;
if(pos==1){
    add_at_Beg(head,data);
   return;
}

Node *p=head;
while(cnt<pos-1){
p=p->next;
cnt++;
}

if(p->next==NULL){
    add_at_End(tail,data);
    return;
}
Node*node_to_insert=new Node(data);
node_to_insert->next=p->next;
p->next->prev=node_to_insert;
p->next=node_to_insert;
node_to_insert->prev=p;
}


void print(Node * head){
Node*temp=head;
 while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
    }

}

void deleteNode(int pos,Node *&head){
if(pos==1){
Node *temp=head;
temp->next->prev=NULL;
head=head->next;
temp->next=NULL;
delete temp;
}
else{
int count=1;
Node *curr=head;
Node* pre=NULL;
while(count<pos){
    pre=curr;
    curr=curr->next;
    count++;
}
curr->prev=NULL;
pre->next=curr->next;
curr->next=NULL;
delete curr;

}



}


int main(){
Node*node1=new Node(100);
Node* head=node1;
Node* tail=node1;
add_at_Beg(head,50);
add_at_End(tail,30);
add_at_Beg(head,20);
add_at_End(tail,60);
add_at_Mid(head,tail,3333,6);
print(head);
deleteNode(3,head);
print(head);
int len=get_Lenght(head);
cout<<"Lenght is ->"<<len<<endl;
cout<<"First data->"<<head->data<<endl;
cout<<"Last data->"<<tail->data;

    return 0;
}