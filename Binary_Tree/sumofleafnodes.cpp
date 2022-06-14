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
int sum=0;
int sum1(Node*root)
{

 
  if(root==NULL)return 0;
   if(root->left==NULL && root->right==NULL)
 {
   sum+=root->data;
 }
 
  sum1(root->left);
  sum1(root->right);

  return sum;
}
void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
}

void inOrder(Node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{   sum=0;
    struct Node *root,*target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    target=root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);
    cout<<sum1(root);

    /*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
    */
   /*vector<int>res;
    //if func returns vector then do -> res = function();
    for(auto x : res){
        cout<<x<<" ";
    }

    Node * ans;*/
    
    return 0;
}