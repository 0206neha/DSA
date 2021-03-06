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

 void helper(Node *root)
{
   if(root==NULL)return;
   if(root->left!=NULL)
   {
       helper(root->left);
       Node *rt=root->right;
       root->right=root->left;
       root->left=NULL;
       
       Node *t=root->right;
       while(t->right!=NULL)
       {
           t=t->right;
       }
       t->right=rt;

   }
   helper(root->right);
   
}

void printInorder(Node *root){
    if(root==NULL){
        cout<<"N"<<" ";
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
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

    cout<<"Before Flattening tree : ";
    printInorder(root);
    cout<<"\nAfter Flattening Tree is ";
    helper(root);
    printInorder(root);

    return 0;
}