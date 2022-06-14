#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void lefts(Node *root,vector<int>&v)
{
  if(root==NULL || root->left==NULL && root->right==NULL)return;
  v.push_back(root->data);
  if(root->left!=NULL)
  lefts(root->left,v);
  else
  lefts(root->right,v);
}

void leaves(Node *root,vector<int>&v)
{
  if(root==NULL)return;
  if(root->left==NULL && root->right==NULL)
  {
      v.push_back(root->data);                           




       /*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
           */ 
      return;
  }
  
  leaves(root->left,v);
  
  leaves(root->right,v);
}

void rights(Node *root,vector<int>&v)
{
  if(root==NULL || root->left==NULL && root->right==NULL)return;
 
 if(root->right!=NULL)
  rights(root->right,v);
 else
  rights(root->left,v);
  
  v.push_back(root->data);
}

vector<int>printboundary(Node *root)
{   
    vector<int>v;
    if(root==NULL)return v;
    v.push_back(root->data);
    lefts(root->left,v);
    leaves(root,v);
    rights(root->right,v);
    return v;
}
int main()
{
    struct Node *root,*target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    target=root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);

    /*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
           */
          vector<int>res;
          res=printboundary(root);
          for(auto x : res){
          cout<<x<<" ";
       
    }
    
    
return 0;
}