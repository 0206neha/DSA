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


void Inorder(Node *root,int k,int &count,int &res)
{
    if(root==NULL)return;

    Inorder(root->left,k,count,res);
    count++;

    if(count==k)
    {
        res=root->data;
        return;
    }

    Inorder(root->right,k,count,res);
}

void Reverse_Inorder(Node *root,int k,int &count,int &res)
{
    if(root==NULL)return;

    Reverse_Inorder(root->right,k,count,res);
    count++;

    if(count==k)
    {
        res=root->data;
        return;
    }
      Reverse_Inorder(root->left,k,count,res);
   
}

int KthLargest(Node *root,int k)
{
    int count=0,res=-1;
    if(root==NULL)return res;
    Reverse_Inorder(root,k,count,res);
    return res;
}

int KthSmallest(Node *root,int k)
{
    int count=0,res=-1;
    if(root==NULL)return res;
    Inorder(root,k,count,res);
    return res;
}

Node *build(vector<int> arr, int l, int h)
{
    if (l > h)
        return NULL;
    int mid = l + (h - l) / 2;
    Node *root = new Node(arr[mid]);
    root->left = build(arr, l, mid - 1);
    root->right = build(arr, mid + 1, h);
    return root;
}
void printInorder(Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    int k=3;
    vector<int> arr = {4, 5, 6, 11, 12, 13};
    Node *root = build(arr, 0, arr.size() - 1);
    printInorder(root);
    cout << "\nKth Largest element is:  "<<KthLargest(root,k);
    cout << "\nKth smallest element is:  "<<KthSmallest(root,k);
    return 0;
}