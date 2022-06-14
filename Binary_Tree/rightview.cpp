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

vector<int>rightview(Node*root)
{
  vector<int>v;
  if(root==NULL)return v;
  queue<Node*>q;
  int n;
  q.push(root);

  while(!q.empty())
  {
    n=q.size();
    for(int i=1;i<=n;i++)
    {
      Node *temp=q.front();
      q.pop();

      if(i==n)
      {
          v.push_back(temp->data);
      }
       if(temp->left!=NULL)
      q.push(temp->left);
      if(temp->right!=NULL)
      q.push(temp->right);


    }


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
   vector<int>ans;
    ans=rightview(root);
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;

}