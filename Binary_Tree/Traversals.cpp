#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};

void Inorder(Node *root)
{   
    stack<Node *>s;

    if(root==NULL)
    return;

    while(1)
    {
        while(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
    }
}
int main()
{
    vector<int> a = {10, 4, 5, 6, 11, 12, 13};
    Node *root = buildBST(a);
    inorder(root);
    cout << "\n";
   // cout<<search(root,21);
   // Node *head=insert(root,7);
    deletion(root,10);
    inorder(root);
    cout << "\n";
}