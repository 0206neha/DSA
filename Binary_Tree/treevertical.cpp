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

vector<int> verticalTraversal(Node *root)
{   
    vector<int>v;
    if(root==NULL)return v;
    map<int,vector<int>>mp;  
    queue<pair<Node*,int>>q;
    pair<Node*,int>p;

    q.push({root,0});
    int n;

    while(!q.empty())
    {
        n=q.size();
        for(int i=1;i<=n;i++)
        {
            p=q.front();
            q.pop();
            Node *node=p.first;
            int d=p.second;

            mp[d].push_back(node->data);

            if(node->left!=NULL)
                q.push({node->left,d-1});
            if(node->right!=NULL)
                q.push({node->right,d+1});
        }
    }

    for(auto x : mp){  //for every pair in map
        for(auto y : x.second){  //for every data in pair  //we can even write int i here
            v.push_back(y);
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
   vector<int>res;
   cout<<"Vertical traversal is : ";
   res=verticalTraversal(root);
   for(auto j:res)
   {
       cout<<j<<" ";
   }
    return 0;
}