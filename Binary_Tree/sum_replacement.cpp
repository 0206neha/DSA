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

int temp=0;
int tree_sum(Node *root)
{
    if(root==NULL)return 0;
  

    int ls=tree_sum(root->left);
    int rs=tree_sum(root->right);
    temp=ls+rs+root->data;
    root->data=ls+rs;

    return temp;
}

void preorder(Node *root)
{
    if(root==NULL)
    {return;}
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{   
   
    struct Node *root;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    preorder(root);
    cout<<endl;
    cout<<"Tree sum is "<<tree_sum(root);
    cout<<endl;
    preorder(root);
    return 0;
}
    /*      1
           /\
          2  3
          /\  /\
        4  5 6   7    1->4+0+0=4
                      2->5+0+0=5
                      3->4+5+2=11
                      4->11
                      5->6+0+0=6
                      6->7+0+0
                      7->6+7+3=16
                      8->16+11+1=28
          */