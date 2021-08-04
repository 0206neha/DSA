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

bool search(Node *root, int val)
{
    if (root == NULL)
        return false;

    if (root->data == val)
        return true;

    if (val < root->data)
    {
        return search(root->left, val);
    }
    return search(root->right, val);
}

Node *insert(Node *root, int val)
{

    if (root == NULL)
    {
        return new Node(val);
    }

    Node *node = new Node(val);
    if (val < root->data)
    {

        root->left = insert(root->left, val);
    }

    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node *find_max(Node *root)
{

    while (root != NULL and root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deletion(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    Node *temp;

    if (root->data == val)
    {
        //no children
        if (root->left == NULL and root->right == NULL)
        {
            delete (root);
            return NULL;
        }

        //1 child

        else if (root->left == NULL)
        {

            temp = root->right;
            delete (root);
            return temp;
        }

        else if (root->right == NULL)
        {
            temp = root->left;
            delete (root);
            return temp;
        }
        else
        {
            //2 child nodes
            temp = find_max(root->left);
            swap(root->data, temp->data);
            root->left = deletion(root->left, val);
        }
    }

    if (val < root->data)
        root->left = deletion(root->left, val);
    else
        root->right = deletion(root->right, val);
    return root;
}
Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (int x : arr)
    {
        root = insert(root, x);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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