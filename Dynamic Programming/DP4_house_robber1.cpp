#include <bits/stdc++.h>
using namespace std;

// input nums = [2,7,9,3,1]
//ouptut=12

/*

recursion  tc=2^n sc=O(n);
memoization tc=O(n) sc=2O(n)
tabulation  tc=O(n) sc=O(n)
space optimization tc=O(n) sc=O(1)
*/


int f(int i,vector<int>&arr,vector<int>&dp)
{

    if(i==0)
    {
        return arr[0];
    }
    if(dp[i]!=-1)return dp[i];
    int nt=f(i-1,arr,dp);
    int t=arr[i];
    if(i>1)t=t+f(i-2,arr,dp);
    return dp[i]= max(nt,t);
}


int robber(int n,vector<int>&arr)
{    
    //recursion
    // return f(n-1,arr);

    //memoization

    // vector<int>dp(n,-1);
    // return f(n-1,arr,dp);

    //tabulation
    // vector<int>dp(n,0);
    // dp[0]=arr[0];
    // for(int i=1;i<n;i++)
    // {
    //     int nt=dp[i-1];
    //     int t=arr[i];
    //     if(i>1)t=t+dp[i-2];
    //     dp[i]= max(nt,t);
    // }

    // return dp[n-1];

    //space optimization

    int p1=arr[0],p2=0;

    for(int i=1;i<n;i++)
    {
        int nt=p1;
        int t=arr[i];
        if(i>1)t=t+p2;
        int curr = max(nt,t);
        p2=p1;
        p1=curr;
    }

    return p1;
}


int main()
{   
    int n;
    cout<<"Enter value for n:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Input:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int a=robber(n,arr);
    cout<<a;
}