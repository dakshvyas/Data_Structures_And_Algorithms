// Morris Traversal
//flatten binary tree to Linked List
#include<iostream>
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

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

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

void Morris_Traversal(Node*root){
Node *curr;
if(root==NULL){
    return ;
}
curr=root;
while (curr!=NULL)
{
  if(curr->left!=NULL){
  Node*temp=curr->left;
  Node*leftPointer=curr->left;
while(temp->right!=NULL){
temp=temp->right;
}
temp->right=curr;
curr->left=NULL;
 curr=leftPointer;
  }
  else{
    cout<<curr->data<<" ";
    curr=curr->right;
  }
}
}

Node*flatten_Binary_tree(Node*root){
Node*curr=root;
while(curr!=NULL){
if(curr->left){
    Node*pred=curr->left;
    while(pred->right)
    pred=pred->right;
  pred->right=curr->right;
  curr->right=curr->left;
  curr->left=NULL;
}
curr=curr->right;
}
return root;
}

int main(){
Node*root=NULL;
root=buildTree(root);
root=flatten_Binary_tree(root);
while(root!=NULL){
    cout<<root->data<<" ";
    root=root->right;
}
//Morris_Traversal(root);

    return 0;
}