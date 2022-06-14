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

Node* LCA(Node *root,int n1,int n2)
{
  if(root==NULL)return NULL;
  if(root->data==n1 || root->data==n2)
  {
     return root;
  }

  Node *l=LCA(root->left,n1,n2);
  Node *r=LCA(root->right,n1,n2);
  if(l==NULL && r==NULL)
  return NULL;
  if(l!=NULL && r!=NULL)
  return root;
  if(l!=NULL)
  return l;
  else
  return r;
}

int find_dist_from_LCA(Node *root,int k,int d)
{
   if(root==NULL)return -1;

   if(root->data==k)return d;

  int ld=find_dist_from_LCA(root->left,k,d+1);
   if(ld!=-1)
   return ld;
   int rd=find_dist_from_LCA(root->right,k,d+1);
   return rd;
}

int calculate(Node *root,int n1,int n2)
{   
    Node *lca=LCA(root,n1,n2);
    int d1=find_dist_from_LCA(lca,n1,0);
    int d2=find_dist_from_LCA(lca,n2,0);
    return d1+d2;
}

int main()
{   
    int n1=4,n2=8;
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
    cout<<"Minimun distance is =";
    cout<<calculate(root,n1,n2);
    
    /*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
    */
   

  
    
    return 0;
}