#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void fillset(Node *root, unordered_set<int> &s)
{
    if (root == NULL)
        return;
    fillset(root->left, s);
    s.insert(root->data);
    fillset(root->right, s);
}

void getcount(Node *root, unordered_set<int> &s, int sum, int &count)
{
    if (root == NULL)
        return;
    if (s.find(sum - root->data) != s.end())
    {
        count++;
    }
    getcount(root->left,s,sum,count);
    getcount(root->right,s,sum,count);
}

int countpairs(Node *root1, Node *root2, int sum)
{
    unordered_set<int> s;
    int count = 0;
    if (root1 == NULL && root2 == NULL)
        return -1;
    fillset(root1, s);
    getcount(root2,s,sum,count);
    return count;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr1 = {2,3,4,5,6,7,8};
    vector<int> arr2 = {3,6,8,10,11,15,18};
    int x = 16; // 3
    Node *root1 = build(arr1,0,arr1.size()-1);
    Node *root2 = build(arr2, 0, arr2.size() - 1);
    printInorder(root1);
    cout <<"\n";
    printInorder(root2);

    cout<<"\nThe count of pairs with sum "
            <<x<<" is "<<countpairs(root1,root2,x);
    return 0;
}