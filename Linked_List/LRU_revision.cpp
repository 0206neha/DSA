#include <bits/stdc++.h>
using namespace std;


    struct Node
    {
        int key, value;
        Node *next, *prev;
        Node(int k, int v)
        {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    struct List
    {
        Node *head, *tail;
        int size;

        List()
        {
            size = 0;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
        // h 1 t
        void add(Node *node)
        {
            node->next = head->next;
            node->prev = head;
            node->next->prev =node;
            head->next = node;
            size++;
        }
    
        void remove(Node *node)
        {
            node->prev->next= node->next;
            node->next->prev =node->prev;
            size--;
        }

    };

    class LRU_cache
    {   
        public:
        int capacity;
        List *dq;
        unordered_map<int,Node*>un; //key with address of node;
        

        LRU_cache(int cap)
        {
            capacity=cap;
            un.clear();
            dq=new List();
        }

        void update(Node *node)
        {  
           dq->remove(node);
           dq->add(node);
           un[node->key]=node;
        }

        int get(int key)
        {
            if(un.find(key)==un.end())
            {
                return -1;
            }

            Node *node=un[key];
            update(node);
            return node->value;
        }

        void set(int key,int value)
        {
            if(un.find(key)!=un.end())
            {   
                Node *node=un[key];
                node->value=value;
                update(node);
                return;
            }
           
           
           if(capacity==dq->size)
           {
               Node* node=dq->tail->prev;
               dq->remove(node);
               un.erase(node->key);
           }
           Node *node =new Node(key,value);
           dq->add(node);
           un[key]=node;

        }
    
    };
    int main()
    {
       LRU_cache l(3);
       cout<<l.get(1)<<endl;
       l.set(1,23);
       l.set(2,45);
       l.set(3,56);
       cout<<l.get(1)<<endl;
       l.set(4,78);
       l.set(5,43);
       cout<<l.get(2)<<endl;
       cout<<l.get(3)<<endl;
       return 0;

    }
