#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void setPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;

    setPreSuc(root->left, pre, suc, key);

    if (root->data < key)
    {
        pre = root;
    }
    else if (suc == NULL && root->data>key)
    {
        suc = root;
        return;
    }
    setPreSuc(root->right, pre, suc, key);
}

Node *BuildBst(vector<int> &v, int l, int h)
{
    if (l > h)
        return NULL;
    int mid = l + (h - l) / 2;
    Node *root = new Node(v[mid]);
    root->left = BuildBst(v, l, mid - 1);
    root->right = BuildBst(v, mid + 1, h);
    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << "->";
    Inorder(root->right);
}

int main()
{
    vector<int> arr = {4, 5, 6, 10, 11, 12, 13};
    Node *root = BuildBst(arr, 0, arr.size() - 1);
    Inorder(root);
    int key = 10;
    Node *pre = NULL, *suc = NULL;
    setPreSuc(root, pre, suc, key);
    cout << "\nPredecessor and Succesor of " << key << " is "
         << ((pre) ? pre->data : -1) << " " << ((suc) ? suc->data : -1);
    return 0;
}