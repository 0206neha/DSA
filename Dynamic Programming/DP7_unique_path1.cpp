// https://leetcode.com/problems/unique-paths/
//Input: m = 3, n = 7
//Output: 28

#include<bits/stdc++.h>
using namespace std;


int f(int i,int j,vector<vector<int>>&dp)
{

    if(i==0 and j==0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=0;
    if(i>0)up=f(i-1,j,dp);
    int left=0;
    if(j>0)left=f(i,j-1,dp);

    return dp[i][j]=up+left;
}


int uniquePaths(int m, int n) 
{
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // return f(n-1,m-1,dp);

    //tabulation
    // vector<vector<int>>dp(n,vector<int>(m,0));
    // dp[0][0]=1;

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {   
    //         if(i == 0 and j == 0)continue;

    //         int up=0;
    //         if(i>0)up=dp[i-1][j];
    //         int left=0;
    //         if(j>0)left=dp[i][j-1];

    //         dp[i][j]=up+left;
    //     }
    // }
    // return dp[n-1][m-1];

    //space optimization

    vector<int>prev(m,0),curr(m,0);
    for(int j=0;j<m;j++)prev[j] = 1;
    curr[0] = 1;

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {   
            if(i == 0 and j == 0)continue;

            int up=0;
            if(i>0)up=prev[j];
            int left=0;
            if(j>0)left=curr[j-1];

            curr[j]=up+left;
        }
        prev=curr;
    }
    return prev[m-1];
}


int main()
{
    int n,m;
    cin>>n>>m;

    cout<<uniquePaths(n, m);
    return 0;
}
