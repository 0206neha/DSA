#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};


int inde;
Node *Preorder(int preorder[],int min,int max,int n)
{
    if(inde>=n)
    return NULL;

    Node *root=NULL;
    int value=preorder[inde];  // we dont know whether val will lie in range or not
                              // hence we dont increment inde here
    
    if(value>min && value<max)  // if the value is in range then insert
    {
      
      root=new Node(value);
      inde++;

      if(inde<n)
      root->left=Preorder(preorder,min,value,n);  //in bst in left side we always update max

      if(inde<n)
      root->right=Preorder(preorder,value,max,n);  //in bst in right side we always update min;


    }

   return root;
}

Node *BuildBst(int preorder[],int i)
{   
    inde=0;
   
    Node *root=Preorder(preorder,INT_MIN,INT_MAX,i);
    
    return root;
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
     int preorder[]={10,5,4,7,6,9,12,13};
    Node *root = BuildBst(preorder,8);
    printInorder(root);
    return 0;
}

