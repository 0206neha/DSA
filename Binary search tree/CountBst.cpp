  
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};



int main()
{
    struct Node *root;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(4);
    root->right = new Node(9);
    //level 2
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(3);
    root->right->right = new Node(11);
    //level 3
    root->right->right->left = new Node(10);
    root->right->left->right = new Node(6);

    /*
            1
           /\
          4  9
          /\  /\
        2  5 3   11
             \  /
             6  10 
    */
    
    cout<<"Largest BST:"<<sizeOfBst(root);
    return 0;
}
