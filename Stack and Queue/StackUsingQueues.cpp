#include <bits/stdc++.h>
using namespace std;

queue<int> q1;
queue<int> q2;

void push(int x)
{
    q1.push(x);
}

int pop()
{
    if (q1.empty() && q2.empty())
        return -1;

    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int ans = q1.front();
    q1.pop();
    swap(q1, q2);
    return ans;

    //Using 1 queue

    // int n=q1.size();
    // int count=1;

    // while(count<n)//ie n-count>1
    // {
    //     q1.push(q1.front());
    //     q1.pop();
    //     count++;
    // }

    // int ans=q1.front();
    // q1.pop();
    // return ans;
}

int top()
{
    if (q1.empty())
        return -1;
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int ans = q1.front();
    q2.push(q1.front());
    swap(q1, q2);
    return ans;

    // int n=q1.size();
    // int count=1;

    // while(count<n)//ie n-count>1
    // {
    //     q1.push(q1.front());
    //     q1.pop();
    //     count++;
    // }

    // int ans=q1.front();
    // q1.push(q1.front());
    // q1.pop();
    // return ans;

}

int main()
{
    push(1);
    push(3);
    cout << top() <<" ";
    push(4);
    cout << pop() <<" ";
    push(5);
    push(6);
    cout << top() <<" ";
    cout << pop() <<" ";
    cout << pop() <<" ";
    cout << top() <<" ";
    return 0;
}