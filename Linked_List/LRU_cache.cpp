#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    int capacity;
    struct node
    {
        /* data */
        int key, value;
        node *prev, *next;

        node(int k, int v)
        {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    struct list
    {
        int size;

        node *head, *tail;

        list()
        {
            size = 0;
            head = new node(-1, -1);
            tail = new node(-1, -1);

            head->next = tail;
            tail->prev = head;
        }

        void add(node *nod)
        {
            nod->next = head->next;
            nod->prev = head;
            head->next->prev = nod;
            head->next = nod;
            size++;
        }

        void remove(node *nod)
        {

            nod->prev->next = nod->next;
            nod->next->prev = nod->prev;
            size--;
        }
    };

public:
    list *dq;
    unordered_map<int, node *> um;

    LRUCache(int val)
    {
        capacity == val;
        dq = new list();
        um.clear();
    }

    void update(node *nod)
    {
        dq->remove(nod);
        dq->add(nod);
        um[nod->key] = nod;
    }

    int get(int key)
    {
        if (um.find(key)== um.end())
            return -1;

        node *nod = um[key];
        update(nod);
        return nod->value;
    }

    void set(int key, int value)
    {
        if (um.find(key) != um.end())
        {
            node *nod = um[key];
            nod->value = value;
            update(nod);
            return;
        }

        if (capacity==dq->size)
        {
            node *nod = dq->tail->prev;
            dq->remove(nod);
            um.erase(nod->key);
        }
        node *nod = new node(key, value);
        dq->add(nod);
        um[key] = nod;
    }
};

int main()
{
    LRUCache lc(3);
    cout<<lc.get(1)<<" ";
    lc.set(1,2);
    lc.set(2,2);
    lc.set(3,3);
    cout<<lc.get(1)<<" ";
    lc.set(4,4);
    cout<<lc.get(2)<<" ";
    lc.set(2,4);
    cout<<lc.get(3)<<" ";
    cout<<lc.get(5)<<" ";

    return 0;

}