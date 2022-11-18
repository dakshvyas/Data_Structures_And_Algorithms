//Height of a binary tree
//Diameter of a binary tree
#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
int data;
Node *left;
Node*right;
Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};

Node*buildTree(Node*root){
cout<<"Enter the data"<<endl;
int data;
cin>>data;
root=new Node(data);
if(data==-1)
return NULL;
cout<<"Enter data for inserting in left of"<<data<<endl;
root->left=buildTree(root->left);
cout<<"Enter data for inserting in right of "<<data<<endl;
root->right=buildTree(root->right);
return root;
}

int height(Node*root){

    if(root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}


int diameter(Node *root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;
    int ans=max(max(op1,op2),op3);
    return ans;
}

//Diameter fast
pair<int,int> diameterFast(Node *root){
if(root==NULL){
    pair<int,int> p=make_pair(0,0);
    return p;
}
pair <int,int>left=diameterFast(root->left);
pair<int,int>right=diameterFast(root->right);
int op1=left.first;
int op2=right.first;
int op3=left.second+right.second+1;
pair<int,int> ans;
ans.first=max(max(op1,op2),op3);
ans.second=max(left.second,right.second)+1;
return ans;
}



// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main(){
Node*root=NULL;
pair<int,int> fastd;
root=buildTree(root);
int h=height(root);
cout<<"Height of this node is ->"<<h<<endl;
int d=diameter(root);
cout<<"Diameter of this node is ->"<<d<<endl;
fastd=diameterFast(root);
cout<<"Fast diameter of this node is ->"<<fastd.first<<endl;
return 0;
}