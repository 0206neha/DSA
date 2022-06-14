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
    
    for(int i=low;i<=high;i++)
    {
        if(in[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node *Build_tree(int in[],int pre[],int low,int high)
{
  static int index=0;
  if(low>high)return NULL;
  int curr=pre[index];
  index++;
  Node *root=new Node(curr);
  root->left=NULL;
  root->right=NULL;

  if(low==high){return root;}

  int pos=search(in,low,high,curr);

  root->left=Build_tree(in,pre,low,pos-1);
  root->right=Build_tree(in,pre,pos+1,high);
  return root;


}

void postorder(Node *root)
{
  if(root==NULL)return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";


}
int main()
{
    int pre[]={1,2,4,3,5};
    int in[]={4,2,1,5,3};

    Node *root=Build_tree(in,pre,0,4);
    cout<<"postorder traversal is"<<endl;
    postorder(root);
    return 0;
}