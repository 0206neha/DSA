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

Node *head=NULL,*tail=NULL;
void DLL(Node *root)
{
  if(root==NULL)return;
  DLL(root->left);
  if(head==NULL)
  {
      head=root;
      tail=root;

  }
  else
  {
      tail->right=root;
      root->left=tail;
      tail=root;
  }
  DLL(root->right);
}

Node *btoDLL(Node *root)
{
    head=NULL;
    tail=NULL;
    DLL(root);
    return head;
}
void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }
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
  btoDLL(root);
  printList(head);
    return 0;
}