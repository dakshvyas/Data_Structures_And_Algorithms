//MIdlle of a Lineked List
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


int getlenght(Node * head){
    int lenght =0;
    Node *ptr=head;
    while(ptr!=NULL){
        ptr=ptr->next;
        lenght++;
    }
return lenght;
}



Node *findMiddle(Node *head) {
    int cnt=0;
    int len=getlenght(head);
    int ans=(len/2);
        Node*temp=head;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;   
}