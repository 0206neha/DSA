#include<bits/stdc++.h>
using namespace std;

struct  Node
{ 
    int data;
 struct Node *left;
 struct Node *right;

Node(int val)
{
   data=val;
   left=NULL;
   right=NULL;
}

};

int height(Node*root)
{
  if(root==NULL)
  return 0;
  //int lh=height(root->left);
  //int rh=height(root_>right);
 // return max(lh,rh);
  return max(height(root->left),height(root->right))+1;

}

int main()
{

    Node *root = new Node(1);      //root->left is of type Node    properties are it has data part left and right part
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->right->right->right=new Node(10);
    cout<<height(root);
}