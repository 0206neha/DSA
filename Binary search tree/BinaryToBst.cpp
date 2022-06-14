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
void inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
void inorderr(Node *root)
{
    if (root == NULL)
        return;
    inorderr(root->left);
    cout<<root->data<<" ";
    inorderr(root->right);
}

int idx;
Node *Changeorg(Node *root,vector<int>&v) 
{
   if(root==NULL)return NULL ;      // here we change original one
   Changeorg(root->left,v);
   root->data=v[idx++];
   Changeorg(root->right,v);
   return root;
}

Node *BinaryTreeToBST(Node *root)
{
   idx=0;
    if (root == NULL)
        return NULL;
    vector<int> v;
    inorder(root, v);
    sort(v.begin(), v.end());

    return Changeorg(root,v);
}
Node *Build(vector<int> &v, int l, int h)
{
    if (l > h)  //here we build new bst
        return NULL;

    int mid = l + (h - l) / 2;

    Node *r = new Node(v[mid]);
    r->left = Build(v, l, mid - 1);
    r->right = Build(v, mid + 1, h);

    return r;
}

Node *binaryTreeToBST(Node *root)
{

    if (root == NULL)
        return NULL;
    vector<int> v;
    inorder(root, v);
    sort(v.begin(), v.end());
    return Build(v, 0, v.size() - 1);
}
Node *build(vector<int>arr,int l,int h)
{
    if(l>h)
     return NULL;
    int mid = l +(h-l)/2;
    Node *root= new Node(arr[mid]);
    root->left = build(arr,l,mid-1);
    root->right = build(arr,mid+1,h);
    return root;
}
void printInorder(Node *root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    
    vector<int> arr = {4,1,2, 5, 6, 10, 11,14, 12, 13};
    Node *root = build(arr, 0, arr.size() - 1);
    printInorder(root);
    cout << "\n";
    Node *r=binaryTreeToBST(root);
    inorderr(r);   // to chk whether it is converted to bst or not
    cout<<endl;
    // change original tree
    Node *ro= BinaryTreeToBST(root);
    inorderr(ro);
    
    return 0;
}