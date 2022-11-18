#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack{
int size ;
int top;
int * arr;
};

int isEmpty( struct stack *ptr){
if(ptr->top==-1){
    return 1;
}
else{
    return 0;
}
}

int isFull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
  return 1; 
    }
    else{

        return 0;
    }
}

int main()
{
 struct stack *s=(struct stack *)malloc(sizeof(struct stack));
s->size=10;
s->top=-1;
s->arr=(int *)malloc(s->size*sizeof (int) );

s->arr[0]=4;
s->top++;

if(isEmpty(s)){
cout<<"Stack is empty";
}
else {
    cout<<"Stack is not empty";
}

if(isFull(s)){
    cout<<"Stack is full";
}
else{
    cout<<"Stack is not full";
}
    return 0;
}