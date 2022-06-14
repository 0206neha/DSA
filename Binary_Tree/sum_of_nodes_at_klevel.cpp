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

int rec_sum(Node *root,int k)
{   
   if(root==NULL)return 0;
    if(k==0)
   {
     return root->data;
   } 
   
    return rec_sum(root->left,k-1)+rec_sum(root->right,k-1);

}
int sum=0;
int sum_rec(Node *root,int k,int level)
{  
    if(root==NULL)return 0;
   
  
    if(level==k){
  sum+=root->data;
  }
  sum_rec(root->left,k,level+1);
  sum_rec(root->right,k,level+1);
  return sum;
  
}

int sumatlevel(Node *root,int k)
{
    if(root==NULL)return 0;
   int sum=0;
   int level=0;
  
 queue<Node*>q;
 int n;
 Node *temp;
 q.push(root);
 while(!q.empty())
 {  
    n=q.size();
    for(int i=1;i<=n;i++)
    {
       temp=q.front();
       q.pop();

       if(level==k)
       {  
          sum+=temp->data;
       }

       if(temp->left!=NULL)
       q.push(temp->left);
       if(temp->right!=NULL)
       q.push(temp->right);
        
   }
   
       if(level==k)
       {  
          break;
         
       }
       
     
     level++;
 }
 return sum;

}


int main()
{
  
   int level=0;
    Node *root = new Node(1);      //root->left is of type Node    properties are it has data part left and right part
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->right->right->right=new Node(10);
    
    cout<<rec_sum(root,3)<<endl;
    cout<<sum_rec(root,2,level)<<endl;;
    cout<<sumatlevel(root,2)<<endl;
    return 0;
}
/*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
                  \
                  10
          
           */