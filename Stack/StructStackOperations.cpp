//Push,Pop,Peek,Display Operation

#include<iostream>
#include<stdlib.h>
using namespace std;
struct stack {
int size;
int top;
int *arr;
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

void Push(struct stack *p,int val){
    if(isFull(p)){
        cout<<"Overflow";
    }
    else{
        p->top++;
        p->arr[p->top]=val;
    }
}

void Pop(struct stack*p){
    if(isEmpty(p)){
        cout<<"Underflow";
    }
    else{
       p->top--;
    }
}
void Peek(struct stack *p){
if(isEmpty(p)){
    cout<<"Underflow";
}
else{
    cout<<"Value at top is : "<<p->arr[p->top]<<endl;
}

}

void Display(struct stack *p){
if(isEmpty(p)){
    cout<<"Underflow";
}
else{
    for(int i=p->top;i>=0;i--){
        cout<<p->arr[i]<<" ";
    }
}
}
int main(){
stack * p=(stack *)malloc(sizeof(struct stack));
p->size=10;
p->top=-1;
p->arr=(int *)malloc(p->size* sizeof(int));
while(1){
    int operation;
    cout<<"\nEnter the the operation you want to perform\n";
    cout<<"1-> Push\n2-> Pop\n3-> Peek\n4->Display\n5->Exit\n";
    
    cin>>operation;
    switch (operation)
    {
    case 1:
    int n;
    cout<<"Enter a number";
    cin>>n;
    Push(p,n);    
        break;
    
    case 2:
    Pop(p);
    break;
     

     case 3:
     Peek(p);
     break;

     case 4:
     Display(p);
     break;

     case 5:
     exit(0);
     break;

    default:
       cout<<"Wrong choice";  
    }


}


    return 0;
}
