#include<iostream>
using namespace std;
struct node{
int i;
struct node *link;
};
int main(){
    struct node *head;
   head=(struct  node*)malloc(sizeof(struct node));
   head->i=65;
   head->link=NULL;

   struct  node *current;
 current=(struct node *)malloc(sizeof( struct node));
 current->i=66;
 current->link=NULL;
 head->link=current;

 current=(struct node *)malloc(sizeof( struct node));
 current->i=66;
 current->link=NULL;
 head->link->link=current;
   return 0;
}