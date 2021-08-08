#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int ele)
{
    if (s.empty())
    {   
        s.push(ele);
        return;
    }
    int currtop = s.top();
    s.pop();
     insert(s,ele);
    s.push(currtop);
   
}

void reverse(stack<int> &st)
{
    if (st.empty())
        return;
    
    int x=st.top();
    st.pop();
    reverse(st);
    insert(st,x);

}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    stack<int> st;
    for (int e : arr)
    {
        st.push(e);
    }

    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}