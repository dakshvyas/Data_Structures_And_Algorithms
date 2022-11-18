//

#include<iostream>
using namespace std;

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


Node* kReverse(Node* head, int k) {
   if(head==NULL){
       return NULL;
   }
    Node*next=NULL;
    Node*cur=head;
    Node*prev=NULL;
    int count=0;
    while(cur!=NULL&&count<k){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        count++;
    }
    if(next!=NULL){
  head->next=kReverse(next,k);
        }
    return prev;
}