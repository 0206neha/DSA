/*
https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
pattern = "ba*a?"
str = "baaabab"
*/


#include <bits/stdc++.h>
using namespace std;


int f(int i,int j,string s,string p,vector<vector<int>>&dp)
{
    if(i==0 && j==0)return 1;

    if(i==0)
    {
         for(int k=1;k<=j;k++)
        {
            if(p[k-1]!='*')
            {
                return 0;
            }
            return 1;
        }
    }

    if(j==0)return 0;


    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==p[j-1] ||p[j-1]=='?')
    {
        return dp[i][j]=f(i-1,j-1,s,p,dp);
    }

    else if(p[j-1]=='*')
    {
        int t=f(i-1,j,s,p,dp);
        int nt=f(i-1,j-1,s,p,dp);
        int empty=f(i,j-1,s,p,dp);

        return dp[i][j]=(t||nt||empty);
    }

    else{
        return dp[i][j]=0;
    }
}


int wildCard(string p, string s)
{
    int n = s.size();
    int m = p.size();

    //memoization
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // return f(n, m, s, p, dp);

    //tabulation
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     for(int i=0;i<=n;i++)
//     {
//         dp[i][0]=0;
//     }

//     for(int j=0;j<=m;j++)
//     {
//         int ans=true;
//         for(int k=1;k<=j;k++)
//         {
//             if(p[k-1]!='*')
//             {
//                 ans=false;
//                 break;
//             }
            
//         }
//         dp[0][j]=ans;
//     }

//     dp[0][0]=1;

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             if(s[i-1]==p[j-1] ||p[j-1]=='?')
//             {
//                 return dp[i][j]=dp[i-1][j-1];
//             }

//             else if(p[j-1]=='*')
//             {
//                 int t=dp[i-1][j];
//                 int nt=dp[i-1][j-1];
//                 int empty=dp[i][j-1];

//                 dp[i][j]=(t||nt||empty);
//             }

//             else{
//                 dp[i][j]=0;
//             }
//         }
//     }

//    return dp[n][m];


    //space optimization
    vector<int>curr(m + 1, 0),prev(m+1,0);

    

    for(int j=0;j<=m;j++)
    {
        int ans=true;
        for(int k=1;k<=j;k++)
        {
            if(p[k-1]!='*')
            {
                ans=false;
                break;
            }
            
        }
        prev[j]=ans;
    }

    prev[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==p[j-1] ||p[j-1]=='?')
            {
                return curr[j]=prev[j-1];
            }

            else if(p[j-1]=='*')
            {
                int t=prev[j];
                int nt=prev[j-1];
                int empty=curr[j-1];

                curr[j]=(t||nt||empty);
            }

            else{
                curr[j]=0;
            }
        }
    }

   return prev[m];


}

int main()
{
    string s, p;
    cin>>s>>p;

    cout<<wildCard(s, p);
    return 0;
}