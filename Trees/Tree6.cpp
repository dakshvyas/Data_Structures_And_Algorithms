//BST-----------Insertion,Search,Deletion

#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
int data;
Node*left;
Node*right;
Node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
}
};


Node*minVal(Node*root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node*DeleteFromBst(Node*root,int val){
//base case
if(root==NULL){
    return root;
}

if(root->data==val){
//0 child 
if(root->left==NULL&&root->right==NULL){
    delete root;
    return NULL;
}
//1 child

//left child
if(root->left!=NULL&&root->right==NULL){
   Node*temp= root->left;
   delete root;
   return temp;
}
//right child
if(root->left==NULL&&root->right!=NULL){
   Node*temp= root->right;
   delete root;
   return temp;
}

//2 child 
if(root->left!=NULL&&root->right!=NULL){
    int mini=minVal(root->right)->data;
    root->data=mini;
    root->right=DeleteFromBst(root->right,mini);
return root;
}


}
else if(root->data >val ){
    root->left=DeleteFromBst(root->left,val);
    return root;
}
else{
    root->right=DeleteFromBst(root->right,val);
    return root;
}



}


void level_Order_traversal(Node * root){
queue <Node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){
Node*temp=q.front();
q.pop();
if(temp==NULL){
    cout<<endl;
    if(!q.empty())
    {
        q.push(NULL);
    }
}
else{
cout<<temp->data<<" ";
if(temp->left){
    q.push(temp->left);
}
if(temp->right)
{
    q.push(temp->right);
}
}

}
}

void inorderTraversal(Node*root){
    if(root==NULL){
        return ;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node*root){
    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node*root){
    if(root==NULL){
        return ;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}


// 10 8 21 7 27 5 4 3 -1

Node* insertIntoBst(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
   if(data > root->data){
   root->right=insertIntoBst(root->right,data);
   }
   else{
    root->left=insertIntoBst(root->left,data);
   }
   return root;
}


void takeInput(Node*&root){
int data;
cin>>data;
while(data!=-1){
    root=insertIntoBst(root,data);
    cin>>data;
}
}

int main(){
Node* root=NULL;
cout<<"Enter the data for bst";
takeInput(root);
cout<<"Level order"<<endl;
level_Order_traversal(root);
cout<<endl;
cout<<"Inorder Traversal"<<endl;
inorderTraversal(root);    
 cout<<endl;
 cout<<"PreOrder traversal"<<endl;
 preorderTraversal(root);
 cout<<endl;
 cout<<"PostOrder traversal"<<endl;
 postorderTraversal(root);
 cout<<endl;   
    
root=DeleteFromBst(root,7);
cout<<"Level order"<<endl;
level_Order_traversal(root);
cout<<endl;
cout<<"Inorder Traversal"<<endl;
inorderTraversal(root);    
 cout<<endl;
 cout<<"PreOrder traversal"<<endl;
 preorderTraversal(root);
 cout<<endl;
 cout<<"PostOrder traversal"<<endl;
 postorderTraversal(root);
 cout<<endl;   


    return 0;
}