#include <bits/stdc++.h>
using namespace std;

//7 2 4 6 81 11 4

void Find(vector<int> v)
{   
    stack<int> s;
    vector<int> ans(v.size());
    
    // if (v.size() == 0)
    //     return;
    
    for (int i = 0; i < v.size(); i++)
    {
        
        while (!s.empty() && v[i] > v[s.top()])
        {

            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        ans[s.top()]=-1;
        s.pop();
    }

    for (int x : ans)
    {
        cout << x<<" ";
    }
}

int main()
{
    vector<int> arr = {7, 2, 4, 6, 81, 11, 4};
    Find(arr);
    return 0;
}