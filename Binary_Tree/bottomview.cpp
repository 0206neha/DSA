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

vector<int>bottom(Node *root)
{
   
   vector<int>v;
   if(root==NULL)return v;
   int n,d;
   map<int,int>mp;
   queue<pair<Node*,int>>q;
   Node *temp;
   pair<Node*,int>p;            //temporary var
   q.push({root,0});

   while(!q.empty())
   {
      n=q.size();
      for(int i=1;i<=n;i++)
      {
           p=q.front();
           q.pop();
           temp=p.first;
           d=p.second;

           mp[d]=temp->data;

          if(temp->left!=NULL)
          q.push({temp->left,d-1});
          if(temp->right!=NULL)
          q.push({temp->right,d+1});



      }
    
   }
  for(auto p:mp)
    {
        v.push_back(p.second);
    }

return v;

}

int main()
{
    struct Node *root;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);

    /*
              1
             /\
            2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
    */
vector<int>res;
res=bottom(root);
cout<<"Bottomview is : ";
for(auto j:res)
   {
       cout<<j<<" ";
   }
    return 0;

}