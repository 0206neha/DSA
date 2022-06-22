/*
link-> https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1/
ip->
good
mode
op->
4
*/
#include<bits/stdc++.h>
using namespace std;

int minOperations(string s1, string s2) 
{ 
    int m=s2.size();
    int n=s1.size();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    // for(int i=0;i<=n;i++)dp[i][0]=0;
    // for(int j=0;j<=m;j++)dp[0][j]=0;

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         if(s1[i-1]==s2[j-1])
    //         {
    //             dp[i][j]=1+dp[i-1][j-1];
    //         }
    //         else
    //         {
    //             dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

    //         }
    //     }
    // }

    // int ans=dp[n][m];
    // return n+m-(2*ans);

    vector<int>prev(m+1,0),curr(m+1,0);

    for(int i=0;i<=n;i++)prev[0]=0;
    for(int j=0;j<=m;j++)prev[j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                curr[j]=1+prev[j-1];
            }
            else
            {
                curr[j]=max(curr[j-1],prev[j]);

            }
        }
        prev=curr;
    }

    int ans=prev[m];
    return n+m-(2*ans);
}

int main()
{
    string a, b;
    cin>>a>>b;

    cout<<minOperations(a, b);
    return 0;
}