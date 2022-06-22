/*
link-> https://leetcode.com/problems/longest-common-subsequence/
ip->
abac
bca
op->
2
Recursion-> tc->O(2^(n*m)) sc->O(n+m)
Memoization-> tc->O(n*m) sc->O(n+m) + O(n*m)
Tabulation-> tc->O(n*m) sc->O(n*m)
Space optimization-> tc->O(n*m) sc->O(2*m)
*/

#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string s, string p,vector<vector<int>>&dp)
{
    if(i==0 ||j==0 )return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    if(s[i-1]==p[j-1])
    {
        return dp[i][j]=1+f(i-1,j-1,s,p,dp);
    }

    else
    {
        int s_nt=f(i-1,j,s,p,dp);
        int p_nt=f(i,j-1,s,p,dp);
        return dp[i][j]=max(s_nt,p_nt);
    }
    
}


int longestCommonSubsequence(string s, string p) 
{
    int n=s.size();
    int m=p.size();

    //memoization
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return f(n,m,s,p,dp);

    //space optimization
         vector<int>prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++)
        {
            prev[j]=0;
        }
        
        curr[0]=prev[0]=0;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1])
              {
                curr[j]=1+prev[j-1];//upper diagonal in dp
              }
        
               else
            {
                int one=prev[j];
                int two=curr[j-1];
                curr[j]=max(one,two);
            }
            }
            
            prev=curr;
        }
        
        return prev[m];
}


int main()
{
    string a, b;
    cin>>a>>b;

    cout << longestCommonSubsequence(a, b);
    return 0;
}