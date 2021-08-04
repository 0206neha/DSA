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

