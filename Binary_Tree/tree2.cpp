//inorder preorder postorder with recursion
//level order

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

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data <<" ";
}
void levelorder(struct Node *root)
{
    queue<Node *> q;
    if (root != NULL)
        q.push(root);

    while (q.empty() != true)
    {
        Node*node=q.front();
        cout << node->data <<" ";
        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);

        q.pop();
    }

}

int main()
{

    Node *root = new Node(1);      //root->left is of type Node    properties are it has data part left and right part
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
}