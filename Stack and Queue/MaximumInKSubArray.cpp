#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int>maxK(vector<int>a,int k)
{
    deque<int>dq;
    vector<int>v;
    int n=a.size();

    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && a[i]>a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    int s=0;
    v.push_back(a[dq.front()]);
    for(int i=k;i<n;i++)   // after above for loop k is at 4 place
    {
        if(s==dq.front())   // here size of queue will be k ex-3 2 1
        {
            dq.pop_front();
        }

        while(!dq.empty() && a[i]>a[dq.back()]) //we are comparing with back as we want greater element in front and smaller at back
        {
            dq.pop_back();  
        }
        s++;
        dq.push_back(i);
        v.push_back(a[dq.front()]);  //at front we have greater elements
    }
    return v;

}
int main()
{
    vector<int>a={3,1,2,4,-1,-3,-6,9,0};
    vector<int>ans=maxK(a,3);
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}