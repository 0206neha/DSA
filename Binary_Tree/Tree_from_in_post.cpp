#include<bits/stdc++.h>
using namespace std;

struct Node
{  

  int data;
  struct Node *right;
  struct Node *left;
  
  Node(int val)
  {
      data=val;
      right=NULL;
      left=NULL;
  }

};

int search(int in[],int low,int high,int curr)
{   
    
    for(int i=high;i>=low;i--)
    {
        if(in[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node *Build_tree(int in[],int post[],int low,int high)
{
  static int index=high;
  if(low>high)return NULL;
  int curr=post[index];
  index--;
  Node *root=new Node(curr);
  root->left=NULL;
  root->right=NULL;

  if(low==high){return root;}

  int pos=search(in,low,high,curr);
   root->right=Build_tree(in,post,pos+1,high);
  root->left=Build_tree(in,post,low,pos-1);
 
  return root;


}

void preorder(Node *root)
{
  if(root==NULL)return;
   cout<<root->data<<" ";
   preorder(root->left);
  preorder(root->right);

}
int main()
{
    int in[]={3,1,4,0,5,2};
    int post[]={3,4,1,5,2,0};

    Node *root=Build_tree(in,post,0,5);
    cout<<"preorder traversal is"<<endl;
    preorder(root);
    return 0;
}