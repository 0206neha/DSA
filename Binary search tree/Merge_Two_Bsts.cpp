#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

vector<int> merge2BSTs(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> s1, s2;
    if (root1 == NULL || root2 == NULL)
        return ans;
    while (1)
    {
        while (root1)
        {
            s1.push(root1);
            root1 = root1->left;
        }

        while (root2)
        {
            s2.push(root2);
            root2 = root2->left;
        }
        
         if (s1.empty() && s2.empty())
            break;

        int x=(s1.empty()?INT_MAX:s1.top()->data);
        int y=(s2.empty()?INT_MAX:s2.top()->data);

        if(x<y)
        {
            ans.push_back(x);
            s1.pop();
            root1=root1->right;
        }
        else{
            ans.push_back(y);
            s2.pop();
            root2=root2->right;
        }




    //     if(!s1.empty() && !s2.empty())
    //     {
    //         if (s1.top()->data < s2.top()->data)
    //         {
    //             root1 = s1.top();
    //             s1.pop();
    //             ans.push_back(root1->data);
    //             root1 = root1->right;
    //         }

    //         else
    //         {
    //             root2 = s2.top();
    //             s2.pop();
    //             ans.push_back(root2->data);
    //             root2 = root2->right;
    //         }
    //     }
    //     else if (!s1.empty())
    //     {
    //         root1 = s1.top();
    //         s1.pop();
    //         ans.push_back(root1->data);
    //         root1 = root1->right;
    //     }
    //     else
    //     {
    //         root2 = s2.top();
    //         s2.pop();
    //         ans.push_back(root2->data);
    //         root2 = root2->right;
    //     }
     }
    return ans;
}

Node *insertion(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (root->data > val)
        root->left = insertion(root->left, val);
    else
    {
        root->right = insertion(root->right, val);
    }

    return root;
}

Node *build(vector<int> arr)
{
    Node *root = NULL;
    for (int a : arr)
    {
        root = insertion(root, a);
    }
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
    vector<int> arr1 = {10, 4, 6, 12, 5, 13, 11};
    vector<int> arr2 = {12, 2, 4, 7 ,10, 9};
    Node *root1 = build(arr1);
    Node *root2 = build(arr2);
    printInorder(root1);
    cout << "\n";
    printInorder(root2);
    cout << "\n\nAfter merging 2 BST's :\n";

    vector<int> res = merge2BSTs(root1, root2);
    for (int x : res)
        cout << x << " ";
    return 0;
}