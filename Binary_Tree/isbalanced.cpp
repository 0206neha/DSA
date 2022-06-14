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

int balanced(Node *root)
{
   if(root==NULL)return 0;

   int ld=balanced(root->left);
   int rd=balanced(root->right);
   
   if(ld==-1 || rd==-1)
   return -1;

   if(abs(ld-rd)<=1)
   return max(ld,rd)+1;
   else
   return -1;
   
}

bool Is_balanced(Node *root)
{
   if(balanced(root)==-1)return false;
   else
   return true;
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
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);

    /*
               1
              /\
            2   3
          /\   /\
        4   5 6  7
             /  /
            9   8 
    */
 
   cout<<Is_balanced(root)<<" ";
   
    return 0;
}