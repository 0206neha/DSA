
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node*left;
    struct Node* right;

    Node(int val)
    {
        data= val;
        left=NULL;
        right=NULL;
    }
};

Node* lca(Node*root,int n1,int n2)
{
    if(root==NULL)
    return NULL;

    if(root->data==n1 || root->data==n2)
    return root;

    Node* leftlca=lca(root->left,n1,n2);
    Node* rightlca=lca(root->right,n1,n2);

    if(leftlca!=NULL && rightlca!=NULL)
    return root;
    if(leftlca==NULL && rightlca==NULL)
    return NULL;

    if(leftlca!=NULL)
    return leftlca;
    else
    return rightlca;


}

int main()
{
    Node *root = new Node(1);      //root->left is of type Node    properties are it has data part left and right part
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->left->left= new Node(5);
   root->right->left= new Node(6);
    root->right->right= new Node(7);
  int n1=7;
  int n2=6;
    Node*LCA=lca(root,n1,n2);
    cout<<LCA->data<<" ";
   
}
/*
                              1
                            /   \
                           2     3
                          / \   / \
                         4   5 6   7

*/