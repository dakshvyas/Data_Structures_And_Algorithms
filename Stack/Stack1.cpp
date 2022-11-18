#include<iostream>
using namespace std;
int top=-1;
#define Max 5
 int st[5];

void push(int val){
    if(top==Max-1){
cout<<"Overflow"<<endl;
    }

    else {
        top++;
    st[top]=val;
    }
}

void pop(){
    if(top==-1){
        cout<<"Underflow"<<endl;
    }
    else{
    cout<<"Value deleted at top is : "<<st[top];
    top--;
    }
}

void peek(){
int val;
    if(top==-1){
        cout<<"Underflow"<<endl;
    }
else
{
    cout<<"Value of top element is: "<<st[top]<<endl;
}
}
void Display(){
if(top==-1){
    cout<<"Underflow"<<endl;
}
else{
    for(int i=top;i>=0;i--){
        cout<<st[i]<<" ";
    }
}
}

int main(){

while(1){
cout<<"Enter the operation you want to perform"<<endl;
cout<<"1->push\n2->pop\n3->peek\n4->Display\n5->Exit"<<endl;
int operation;
scanf("%d",&operation);
switch(operation){
  
    case 1:
    int num; 
    cout<<"Enter the value you want to push";
    cin>>num;
    push(num);
    break;
    
    case 2:
    pop();
    break;
    
    case 3:
    peek();
    break;

    case 4:
    Display();
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



