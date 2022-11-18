
//Creation of Binary tree
//Level Order Traversal
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

void build_From_LevelOrder(Node *&root){
queue <Node*>q ;
cout<<"Enter data for root node";
int data;
cin>>data;
root=new Node(data);
q.push(root);
while (!q.empty())
{
   Node *temp=q.front();
   q.pop();

   cout<<"Enter the data for left node of "<<temp->data;
   int leftNode;
   cin>>leftNode;
   if(leftNode!=-1){
    temp->left=new Node(leftNode);
    q.push(temp->left);
   }

    cout<<"Enter the data for right node of "<<temp->data;
   int rightNode;
   cin>>rightNode;
   if(rightNode!=-1){
    temp->right=new Node(rightNode);
    q.push(temp->right);
   }
}


}

int main(){
Node*root=NULL;
//Creation of tree
/*
root=buildTree(root);
//Level order traversal
level_Order_traversal(root);

//Inorder Traversal
cout<<" Inorder Traversal is : ";
inorderTraversal(root);
cout<<endl;

//Preorder Traversal
cout<<" Preorder Traversal is : ";
preorderTraversal(root);
cout<<endl;
//Postorder Traversal
cout<<" Postorder Traversal is : ";
postorderTraversal(root);  
  cout<<endl;
*/
build_From_LevelOrder(root);
level_Order_traversal(root);
    return 0;
}