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

void flatten(Node*root)
{
  if(root==NULL ||(root->left==NULL && root->right==NULL))
  return;

  if(root->left!=NULL)   
  {   
    flatten(root->left);                  
                                        
  Node  *temp=root->right;  //store root right value temporarily in temp as we are going to attach root left there
  root->right=root->left;  //root right is now left one
  root->left=NULL;

  Node *tail=root->right;  //to calculate tail of right side so that we can attach
  while(tail->right!=NULL)
{
  tail=tail->right;
}
  tail->right=temp;
  }
  flatten(root->right);
}

void inorderprint(Node *root)
{
  if(root==NULL)
  {
    return;
  }
  inorderprint(root->left);
  cout<<root->data<<" ";
  inorderprint(root->right);
}
/*

             4                4
           /   \               \
          9     5   ==          9         ==inorder= 4 9 1 3 5 6
         / \   / \               \
        1   3  6  7               1
                                   \
                                    3
                                     \
                                      5
                                       \
                                        6
                                         \
                                          7
                                         
                                           
*/


int main()
{

Node *root=new Node(4);
  root->left=new Node(9);
  root->right=new Node(5);
  root->left->left=new Node(1);
  root->left->right=new Node(3);
   root->right->left=new Node(6);
  root->right->right=new Node(7);
  
  cout<<"Flattened tree is:";
  //Node *flat= flatten(root);
  flatten(root);
  inorderprint(root);
  cout<<endl;
}