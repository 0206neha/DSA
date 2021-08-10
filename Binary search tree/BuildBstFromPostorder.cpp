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
Node *Postorder(int postorder[],int min,int max)
{
    if(inde<0)
    return NULL;

    Node *root=NULL;
    int value=postorder[inde];  // we dont know whether val will lie in range or not
                              // hence we dont increment inde here
    
    if(value>min && value<max)  // if the value is in range then insert
    {
      
      root=new Node(value);
      inde--;

    
      if(inde>=0)
      root->right=Postorder(postorder,value,max);  //in bst in right side we always update min;
    
      if(inde>=0)
      root->left=Postorder(postorder,min,value)
      ;  //in bst in left side we always update max


    }

   return root;
}

Node *BuildBst(int postorder[],int i)
{   
    inde=i-1;
   
    Node *root=Postorder(postorder,INT_MIN,INT_MAX);
    
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
     int postorder[]={1, 7 ,5, 50 ,40, 10};
    Node *root = BuildBst(postorder,6);
    printInorder(root);
    return 0;
}

