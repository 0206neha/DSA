#include<bits/stdc++.h>
using namespace std;

stack<int>s1;
stack<int>s2;

void push(int x)
{
    s1.push(x);
}

int pop()
{
    if(s1.empty() && s2.empty())
    return -1;

    while(!s1.empty())
    {
        while(s2.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int ans=s2.top();
    s2.pop();
    return ans;
}

int front()
{
    if(s1.empty() && s2.empty())
    return -1;

    while(!s1.empty())
    {
        while(s2.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int ans=s2.top();
    return ans;
}

int main()
{
    push(1);
    push(3);
    cout<<front()<<"";
    push(4);
    cout<<pop()<<"";
    push(5);
    push(6);
    cout<<front()<<"";
    cout<<pop()<<"";
    cout<<pop()<<"";
    cout<<front()<<"";
    return 0;
}