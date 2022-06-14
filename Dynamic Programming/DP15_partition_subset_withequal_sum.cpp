/*
link-> https://leetcode.com/problems/partition-equal-subset-sum/
Given a non-empty array nums containing only positive integers,
find if the array can be partitioned into two subsets such that the
sum of elements in both subsets is equal.
ip->
4
1 5 11 5
op->
1
Recursion-> tc->O(2^(n*k)) sc->O(n)
Memoization-> tc->O(n*k) sc->O(n) + O(n*k)
Tabulation->  tc->O(n*k) sc->O(n*k)
space optimization-> tc->tc->O(n*k) sc->O(2*k)
*/

#include<bits/stdc++.h>
using namespace std;

bool f(int i,int k,vector<int>&arr,vector<vector<int>>&dp)
{
    if(k==0)return true;
    if(i==0)
    {
        if(arr[0]==k)return true;
        else return false;
    }

    int nt=f(i-1,k,arr,dp);
    int t=false;
    if(k>=arr[i])t=f(i-1,k-arr[i],arr,dp);
    return dp[i][k]= (t||nt);

} 

bool canPartition(int n,vector<int>&arr)
{   

    int sum=0;
    for(auto x:arr)int sum= sum+x;
    if(sum%2==1)return 0;
    int k=sum%2;

    //memoization
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // return f(n-1,k,arr,dp);

    //tabulation

    // vector<vector<int>>dp(n,vector<int>(k+1,0));
    // for(int i=0;i<n;i++)dp[i][0]=1;
    // for(int target=1;target<=k;target++)dp[0][target]=(arr[0]==k);

    // for(int i=1;i<n;i++)
    // {
    //     for(int target=1;target<=k;target++)
    //     {
    //         int nt=dp[i-1][k];
    //         int t=false;
    //         if(k>=arr[i])t=dp[i][k-arr[i]];
    //         dp[i][k]= (t||nt);
    //     }
    // }
    // return dp[n-1][k];

    //space optimization

    vector<int>prev(k+1,0),curr(k+1,0);

    prev[0]=curr[0]=1;
    for(int target=1;target<=k;target++) prev[target]=(arr[0]==k);

    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            int nt=prev[k];
            int t=false;
            if(k>=arr[i])t=prev[k-arr[i]];
            curr[k]= (t||nt);
        }

        prev=curr;
    }
    return prev[k];



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
    cout<<canPartition(n,arr);
    return 0;

}