/*
https://leetcode.com/problems/regular-expression-matching/
input=aa  a
output-false
*/

#include <bits/stdc++.h>
using namespace std;


bool f(int i,int j,string s,string p,vector<vector<int>>&dp)
{


    if(i==0 && j==0)return 1;

    if(i==0)
    {
        if(j%2==1)return 0;

        for(int k=2;k<=j;k+=2)
        {
             if(p[k-1]!='*')
            {
                return 0;
            }
            return 1;
        }
       
    }

    if(j==0)return dp[i][j]=0;

    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==p[j-1])
    {
        return dp[i][j]=f(i-1,j-1,s,p,dp);
    }

    else if(p[j-1]=='*')
    {
        if(s[i-1]==p[j-2]||p[j-2]=='.')
        {
            int t=f(i-1,j,s,p,dp);
            int nt=f(i,j-2,s,p,dp);
            return dp[i][j]=(t||nt);
        }
        else
        {
             int nt=f(i,j-2,s,p,dp);
             return dp[i][j]=(nt);
        }
    }

    else{
        return dp[i][j]=0;
    }
}
bool isMatch(string s, string p)
{
    int n=s.size();
    int m=p.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return f(n,m,s,p,dp);


}
int main()
{
    string s, p;
    cin>>s>>p;

    cout<<isMatch(s, p);
    return 0;
}