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
pair<int,int>calcdia(Node *root)
{
 if(root==NULL)return{0,0};

 pair<int,int>ldia=calcdia(root->left);
 pair<int,int>rdia=calcdia(root->right);

 int ht=max(ldia.first,rdia.first)+1;
 int dia=max(max(ldia.second,rdia.second),ldia.first+rdia.first+1);

return {ht,dia};

}


int main()
{

    Node *root = new Node(1);     
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    root->right->right->right=new Node(10);
   
   cout<<calcdia(root).second;
   
}