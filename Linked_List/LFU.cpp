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

struct List
{
    int size;
    Node *head, *tail;

    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        size = 0;
        head->next = tail;
        tail->prev = NULL;
    }
    // h 1 t
    void add(Node *node)
    {
        node->next=head->next;
        node->prev = head;
        head->next = node;
        node->next->prev=node;
        size++;
    }

    void remove(Node *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        size--;
    }
};

class LFU_cache
{
public:
    int capacity;
    unordered_map<int, Node *> um;
    unordered_map<int, List *> freqlist;
    int minfreq, count;

    LFU_cache(int cap)
    {
        capacity = cap;
        minfreq = 1;
        count = 0;
        um.clear();
        freqlist.clear();
    }

    void update(Node *node)
    {
        freqlist[node->freq]->remove(node);

        if (node->freq == minfreq && freqlist[node->freq]->size == 0)
            minfreq++;

        List *nextlist = new List();
        if (freqlist.find(node->freq + 1) != freqlist.end())
            nextlist = freqlist[node->freq + 1];

        node->freq++;
        nextlist->add(node);
        freqlist[node->freq] = nextlist;
        um[node->key] = node;
    }

    int get(int key)
    {
        if (um.find(key) == um.end())
        {
            return -1;
        }

        Node *node = um[key];
        update(node);
        return node->value;
    }

    void set(int key, int value)
    {
        if (capacity == 0)
            return;
        if (um.find(key) != um.end())
        {
            Node *node = um[key];
            node->value = value;
            update(node);
            return;
        }

        if (capacity == count)
        {
            Node *node = freqlist[minfreq]->tail->prev;
            freqlist[minfreq]->remove(node);
            um.erase(node->key);
            count--;
        }

        minfreq = 1;
        count++;
        List *l = new List(); //for ex- when we add 1 node freqlist will not exist

        if (freqlist.find(minfreq) != freqlist.end()) //if minfreq for ex 1 already exists
            l = freqlist[minfreq];

        Node *node = new Node(key, value);
        l->add(node);
        

        um[key] = node; //update both maps
        freqlist[minfreq] = l;
    }
};

int main()
{
    LFU_cache l(2);
    l.set(1, 2);
    l.set(2, 4);
    cout << l.get(1) << endl;
    cout << l.get(3) <<endl;
    l.set(2, 5);
    l.set(3, 8);
    cout << l.get(2) <<endl;
    cout << l.get(1) <<endl;
    l.set(3,9);
    l.set(4,7);
    l.set(3,8);
    cout<<l.get(4)<<endl;
    cout<<l.get(3)<<endl;
    cout<<l.get(2)<<endl;
    
    return 0;
}
