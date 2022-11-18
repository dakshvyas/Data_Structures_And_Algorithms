//ZIG-ZAG Traversal
//Boundary Traversal
#include<iostream>
#include<queue>
#include<vector>
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

vector<int> zig_Zag(Node *root){
vector<int>result;
if(root==NULL){
return result;
}
queue<Node*>q;
q.push(root);
bool lefttoRight=true;
while (!q.empty())
{
int size=q.size();
vector<int> ans(size);
for(int i=0;i<size;i++){
Node*frontNode=q.front();
q.pop();

int index =lefttoRight?i:size-i-1;
ans[index]=frontNode->data;

if(frontNode->left)
{
    q.push(frontNode->left);
}
if(frontNode->right){
    q.push(frontNode->right);
}

}
lefttoRight=!lefttoRight;
for(auto i:ans){
    result.push_back(i);
}

}

return result;
}


void traversalLeft(Node *root,vector<int>&ans)
{
if((root==NULL)||(root->left==NULL&&root->right==NULL))
return ;
ans.push_back(root->data);
if(root->left){
traversalLeft(root->left,ans);
}
else{
    traversalLeft(root->right,ans);
}
}

void leafNode(Node*root,vector<int>&ans){
if(root==NULL)
return ;
if(root->left==NULL&&root->right==NULL){
    ans.push_back(root->data);
    return ;
}
leafNode(root->left,ans);
leafNode(root->right,ans);
}

void traversalRight(Node*root,vector<int>&ans){
if((root==NULL)||(root->left==NULL&&root->right==NULL))
return ;
if(root->right){
    traversalRight(root->right,ans);
}
else{
    traversalRight(root->left,ans);
}
ans.push_back(root->data);
}

vector<int>Boundary_Traversal(Node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
   ans.push_back(root->data);
   traversalLeft(root->left,ans);
   leafNode(root->left,ans);
   leafNode(root->right,ans);
   traversalRight(root->right,ans);
   return ans;
}

int main(){
Node * root=NULL;
root=buildTree(root);
vector<int> ans;
vector<int>result;
ans=zig_Zag(root);
cout<<"Zig zag traversal"<<endl;
for(auto i:ans){
    cout<<i<<" ";
} 
cout<<endl;
cout<<"Boundary traversal is :"<<endl; 
result=Boundary_Traversal(root);
for(auto i : result){
    cout<<i<<" ";
}
 return 0;
}