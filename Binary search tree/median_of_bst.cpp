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

vector<int> v;
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
}

float median_usingspace(Node *root)
{
    v.clear();
    inorder(root);
    if (root == NULL)
        return 0.0;

    int n = v.size();
    float ans;

    if (n % 2 == 0)
    {
        ans = (v[(n / 2)] + v[(n - 1) / 2]) / 2.0f;
    }
    else
        ans = v[n / 2];
    return ans;
}

void counting(Node *root, int &c)
{
    if (root == NULL)
        return;
    counting(root->left, c);
    c++;
    counting(root->right, c);
}

void FindMedian(Node *root, Node *&f, Node *&s, int k, int &c)
{
    if (root == NULL)
        return;

    FindMedian(root->left, f, s, k, c);
    c++;
    if (c == k)
    {
        f = root;
    }
    if (c == k+1)
    {
        s = root;
        return;
    }
    FindMedian(root->right, f, s, k, c);
}

float ans(Node *root)
{
    if (root == NULL)
        return 0.0;

    int c = 1;
    counting(root, c);

    bool isEven = (c % 2 == 0) ? 0 : 1;
    int k = c / 2;
    c = 0;
    Node *s = NULL, *f = NULL;
    FindMedian(root, f, s, k, c);

    if (isEven)
    {
        return (f->data + s->data)/2.0f;
    }
    else
    {
        return s->data;
    }
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {4, 5, 6, 11, 12, 13};
    Node *root = build(arr, 0, arr.size() - 1);
    printInorder(root);
    cout << "\nMedian if bst is : " << median_usingspace(root);
    cout << "\nMedian is:"<< ans(root);
    return 0;
}