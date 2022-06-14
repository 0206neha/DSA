#include <bits/stdc++.h>
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
vector<int> zigzagp(Node*root)
{ 
   vector<int>v;
  if(root==NULL)
  return v;
  stack<int>s;
  queue<Node*>q;
  
  int level=0,n;
  
  q.push(root);

  while(!q.empty())
  {
     n=q.size();
     for(int i=1;i<=n;i++)
     {
         Node *temp=q.front();
         q.pop();
         if(level%2==1)
         {
           s.push(temp->data);
         }
         else
           v.push_back(temp->data);
         if(temp->left!=NULL)
           q.push(temp->left);
         if(temp->right!=NULL)
           q.push(temp->right);
     }
     level++;
  
  while(!s.empty())
  {
     v.push_back(s.top());
     s.pop();
  }
  }
return v;

}


int main()
{

Node *root=new Node(1);
  root->left=new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->left=new Node(6);
  root->right->right=new Node(7);

  vector<int>res;
  res=zigzagp(root);
  for(auto x:res)
  {
     cout<<x<<" ";
  }


}

/*
                              1
                            /   \
                           2     3
                          / \   / \
                         4   5 6   7

*/