#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    struct node
    {
        int key;
        int value;
        node(int k, int v)
        {
            key = k;
            value = v;
        }
    };

private:
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> um; //similar as int,Node* as iterator is pointer iterator pomits address of nodes
    int capacity;
    
    public:
    LRUCache(int c)
    {
        capacity=c;     
        um.clear();
        dq.clear();
    }

    void update(list<pair<int, int>>::iterator it)
    {
        dq.erase(it);
        dq.push_front({it->first,it->second});
        um[(*it).first]=dq.begin();
    }

    int get(int key)
    {
        if(um.find(key)==um.end())
        {
            return -1;
        }

        auto it=um[key];
        update(it);
        return (*it).second;
    }

    void set(int key,int value)
    {
        if(um.find(key)!=um.end())
        {
            auto it=um[key];
            it->second=value;
            update(it);
            return;
        }

        if(dq.size()==capacity)
        {   
            int key=dq.back().first;
            dq.pop_back();
            um.erase(key);
        }
       
       dq.push_front({key,value});
       um[key]=dq.begin();

    }


};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LRUCache lc(3);
    cout << lc.get(1) << endl;
    lc.set(1, 2);
    lc.set(2, 2);
    lc.set(3, 3);
    cout << lc.get(1) << endl;
    lc.set(4, 4);
    cout << lc.get(2) << endl;
    lc.set(2, 4);
    cout << lc.get(3) << endl;
    cout << lc.get(5) << endl;
    lc.set(2, 3);
    lc.set(4, 5);
    lc.set(5, 5);
    cout << lc.get(3) << endl;

    return 0;
}