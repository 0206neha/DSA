#include<bits/stdc++.h>
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

void subtree(Node *root,int k)
{
  if(root==NULL)return;
  


}