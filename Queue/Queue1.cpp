//Circular Queue
#include<iostream>
#include<queue>
using namespace std;
class Queue{
int *arr ;
int size;
int front;
int rear;
public:
Queue(){
    size=5;
    arr=new int[size];
    front=-1;
    rear=-1;
}
bool enqueue(int data){
    if((front==0 && rear==size-1)||(rear==(front-1)%(size-1))){
        cout<<"Queue is Full"<<endl;
        return false;
    }
    else if(front==-1)
    {
    front=rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=data;
    return true;
}

int dequeue(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
   int ans=arr[front];
   arr[front]=-1;
   if(front==rear){
    front=rear=-1;
   }
else if(front==size-1){
    front=0;
}
else{
    front++;
}
return ans;
}

};

int main(){
Queue q1;
q1.enqueue(11);
q1.enqueue(22);
q1.enqueue(33);
q1.enqueue(44);




    return 0;
}







//Implementation of queue
/*
class Queue{
int *arr;
int size;
int front;
int rear;
public:
Queue(){
    size=100001;
    arr=new int[size];
     front=0;
     rear=0;
}

void enqueue(int data)
{
if(rear==size){
    cout<<"Queue is Full";
}
else{
arr[rear]=data;
rear++;
}
}
//return deleted element
int dequeue(){
if(rear==front){
    return -1;
}
else{
int ans=arr[front];
arr[front]=-1;
front++;
if(front==rear){
    front=0;
    rear=0;
}
return ans;
}
}
int fronti(){
    if(front==rear){
        return -1;
    }
else{
    int ans=arr[front];
    return ans;
}

}
bool isEmpty(){
    if(front==rear){
        return true;
    }
    else{
        return false;
    }
}


};



int main(){

Queue q1;
q1.enqueue(20);
q1.enqueue(40);
cout<<q1.fronti()<<endl;
q1.dequeue();
cout<<q1.fronti()<<endl;
cout<<q1.isEmpty()<<endl;
q1.dequeue();
cout<<q1.isEmpty()<<endl;


    return 0;
}
*/

//STL
/*int main(){
queue<int>q;
q.push(11);
q.push(22);
cout<<q.front()<<endl;
q.push(33);
q.pop();
cout<<q.front()<<endl;
cout<<q.empty()<<endl;
cout<<q.size();
    return 0;
}
*/