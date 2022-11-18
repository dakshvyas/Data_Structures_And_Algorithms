//2 Stacks in an array implementation


#include<iostream>
using namespace std;
class TwoStack {

public:
    int size;
    int *arr;
    int top1,top2;
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size=s;
        arr=new int[s];
        top1=-1;
        top2=s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1>=0){
            return arr[top1--];
        }
        else return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2<size){
            return arr[top2++];
        }
        else return -1;
    }
};



int main(){
TwoStack s1(6);
s1.push1(11);
s1.push2(55);
s1.pop1();
cout<<"top element of "<<s1.top2;
    return 0;
}







//Implementation of a stack
/*
class Stack{
public:
int size;
int *arr;
int top;
Stack(int size){
    this->size=size;
    arr=new int[size];
    top=-1;
}
void push(int element){
if(size-top>1){
    top++;
    arr[top]=element;
}
else{
    cout<<"Stack Overflow";
}

}

void pop(){
    if(top>=0){
        top--;
    }
    else{
        cout<<"Stack Underflow";
    }
}

void peek(){
    if(top>=0){
        int ans=arr[top];
        cout<<"Top element is ->"<<ans;
    }
    else{
        cout<<"Stack Underflow";
    }
}

bool isEmpty(){
    if(top==-1){
    return true;
    }
    else
    return false;
}


};


int main(){
Stack s1(5);
s1.push(22);
s1.push(33);
s1.push(44);
s1.peek();
s1.pop();
s1.peek();
if(s1.isEmpty())
{
    cout<<"Stack is empty";
}
else
cout<<"Stack is not empty";

  return 0;
}

//Stack using the STL
#include<stack>
stack <int> s1,s2;
s2.push(100);
s2.emplace(110);
s2.emplace(120);
cout<<"Size of second stack is "<<s2.size()<<endl;
s1.push(11);
cout<<s1.top();
s1.emplace(22);
cout<<s1.top()<<endl;
cout<<s1.empty()<<endl;
s1.push(33);
cout<<s1.top()<<endl;
cout<<"Size of first stack is "<<s1.size()<<endl;
s1.swap(s2);
cout<<"Top of stack 1 is "<<s1.top()<<"Top of stack 2 is "<<s2.top()<<endl;
*/