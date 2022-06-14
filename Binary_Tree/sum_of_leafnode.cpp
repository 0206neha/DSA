#include<bits/stdc++.h>
using namespace std;

struct  Node
{ 
    int data;
 struct Node *left;
 struct Node *right;
                       //we can also find using inorder traversal
                       
Node(int val)
{
   data=val;
   left=NULL;
   right=NULL;
}

};
int sum;
int sumleaf(Node *root)
{
    
  if(root==NULL)
  return 0;

if(root->left==NULL && root->right==NULL)
{
sum+=root->data;
}
sumleaf(root->left);
sumleaf(root->right);
return sum;
}

int main()
{
   int sum=0;
    Node *root = new Node(1);      //root->left is of type Node    properties are it has data part left and right part
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->right->right->right=new Node(10);
    cout<<sumleaf(root);
}

