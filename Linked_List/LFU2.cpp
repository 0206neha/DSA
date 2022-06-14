#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value;
    int freq;
    Node *next, *prev;

    Node(int k, int v)
    {
        key = k;
        value = v;
        freq = 1;
        prev = NULL;
        next = NULL;
    }
};




class LFU
{
    unordered_map<int,pair<int,int>>mp;
    unordered_map<int,pair<int,int>>freqlist;
};



