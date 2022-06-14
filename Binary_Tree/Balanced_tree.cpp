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

int helper(Node *root)
{
  if(root==NULL)return 0;
  int ls=helper(root->left);
  int rs=helper(root->right);

  if(abs(ls-rs)>1)return -1;
  if(ls==-1 || rs==-1)return -1;
  return max(ls,rs)+1;


}

bool balanced(Node *root)
{
  if(helper(root)==-1)return false;
  else
  return true;

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
   // root->right->right->right->right=new Node(11);
    cout<<balanced(root);
    return 0;
}
/*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
                  \
                  10
          
           */