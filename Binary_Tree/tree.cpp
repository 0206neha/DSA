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

void inorder(struct Node *root)
{
  if(root==NULL)
  {
      return;
  }

  inorder(root->left);
  cout<<root->data << " ";
  inorder(root->right);

}

void preorder(struct Node *root)
{
    if(root==NULL)
      return;
  cout<<root->data << " ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(struct Node *root)
{
    if(root==NULL)
      return;
  
  postorder(root->left);
  postorder(root->right);
  cout<<root->data << " ";
}

void levelorder(struct Node *root)
{
  queue<Node*>q;
      int n;
      if(root==NULL)
      return;
      
      q.push(root);
      while(!q.empty())
      {
          n=q.size();
          for(int i=1;i<=n;i++)
          {
              Node *temp=q.front();
              q.pop();
             
             cout<<temp->data<<" ";
              
              if(temp->left!=NULL)
                  q.push(temp->left);
              if(temp->right!=NULL)
                  q.push(temp->right);    
              
          }
      }
      
      
    }

int main()
{
   Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->left=new Node(6);
  root->right->right=new Node(7);
  cout<<"\n Preorder Traversal of binary tree is:-"<<" ";
  preorder(root);
  cout<<"\n inorder Traversal of binary tree is:-"<<" ";
  inorder(root);
  cout<<"\n Postorder Traversal of binary tree is:-"<<" ";
  postorder(root);
  cout<<"\n Levelorder traversal is"<<" ";
  levelorder(root);
  
return 0;
}