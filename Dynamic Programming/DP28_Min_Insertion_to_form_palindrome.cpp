/*
link-> https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/
#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string a,string b, vector<vector<int>>&dp)
{
    if(i==0 || j==0)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    if(a[i-1]==b[j-1])
    {
        dp[i][j]=1+f(i-1,j-1,a,b,dp);
    }
    else
    {
        dp[i][j]=max(f(i-1,j,a,b,dp),f(i,j-1,a,b,dp));
    }

    return dp[i][j];
}
 int minInsertions(string s) {
        
        string a=s;
        reverse(s.begin(),s.end());
        string b=s;
        int n=s.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans= f(n,n,a,b,dp);
        // return n-ans;

        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)dp[i][0];
        for(int j=0;j<=n;j++)dp[0][j];

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                 if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int ans=dp[n][n];
        return n-ans;
 }

int main()
{
    string a;

    cin >> a;

    cout << minInsertions(a);
    return 0;
}