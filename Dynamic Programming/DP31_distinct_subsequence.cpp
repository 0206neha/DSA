/*
link-> https://leetcode.com/problems/distinct-subsequences/
ip->
babgbag
bag
op->
5
*/
#include <bits/stdc++.h>
using namespace std;

int mod = int(1e9 + 7);

int f(int i,int j,string s,string t,vector<vector<int>>&dp)
{
    if(j==0)return 1;
    if(i==0)return 0;
    
    
    

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i-1]==t[j-1])
    {
        int ta=f(i-1,j-1,s,t,dp);
        int nt=f(i-1,j,s,t,dp);
        return dp[i][j]=(ta+nt)%mod;
    }
    else
    {
        int nt=f(i-1,j,s,t,dp);
        return dp[i][j]=nt;
    }
}

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    if(m>n)return 0;
    return f(n,m,s,t,dp);
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<numDistinct(s, t);
    return 0;
}