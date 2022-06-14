#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


void  helper(Node *root,Node *&prev,Node *&v,Node *&a,Node *&z)
{  
   if(root==NULL)return;
   
   helper(root->left,prev,v,a,z);
   
   if(prev!=NULL && root->data<prev->data)
   {  
       if(v==NULL)
       {
         v=prev;
         a=root;
       }
       else
       {
           z=root;
       }
   }
  
   prev=root;
   helper(root->right,prev,v,a,z);

}


Node *recoverBST(Node *root)
{
    Node *prev=NULL,*v=NULL,*a=NULL,*z=NULL;
    helper(root,prev,v,a,z);
    if(v && a && z)  // if condn is violated 2 time ,i.e non adjacent nodes ex-4 5 12 10 11 6 13
    {
        swap(v->data,z->data);
    }
    else if(v && a) // adjacent nodes ex-4 5 10 6 11 12 13
    { 
        swap(v->data,a->data);
    }
    return root;
}

Node *build(vector<int>arr,int l,int h)
{
    if(l>h)
      return NULL;
    int mid=l+(h-l)/2;

    Node *root=new Node(arr[mid]);
    root->left=build(arr,l,mid-1);
    root->right=build(arr,mid+1,h);
    return root;
}
void printInorder(Node *root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
   
    vector<int> arr = {4,5,6,10,11,12,13};
    Node *root = build(arr,0,arr.size()-1);
    // swap(root->left->right->data ,root->right->data);// nodes are not adjacent
    swap(root->data , root->left->right->data);
    printInorder(root);
    cout <<"\n";
    printInorder(recoverBST(root));
    return 0;
}