/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
Input: prices = [7,1,5,3,6,4]
Output: 7
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i,int buy,int n,vector<int>&prices, vector<vector<int>>&dp)
{
    if(i==n-1)
    {
        if(buy==1)return 0;
        else return prices[i];
    }

    if(dp[i][buy]!=-1)return dp[i][buy];

    //buy
    if(buy==1)
    {
        int b=-prices[i]+f(i+1,0,n,prices,dp);
        int nb=f(i+1,1,n,prices,dp);
        return dp[i][buy]=max(max(b,nb),0);
    }

    else
    {
        int s=+prices[i]+f(i+1,1,n,prices,dp);
        int ns=0+f(i+1,0,n,prices,dp);
        return dp[i][buy]=max(s,ns);
    }
}

int maxProfit(vector<int>& prices) 
{
    int n=prices.size();
    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // return f(0,1,n,prices,dp);


    //tabulation

    // vector<vector<int>>dp(n,vector<int>(2,0));
    
    // dp[n-1][0]=prices[n-1];
    // dp[n-1][1]=0;

    // for(int i=n-2;i>=0;i--)
    // {
    //     for(int buy=0;buy<=1;buy++)
    //     {
    //         if(buy==1)
    //         {
    //             int b=-prices[i]+dp[i+1][0];
    //             int nb=dp[i+1][1];
    //             dp[i][buy]=max(max(b,nb),0);
    //         }

    //         else
    //         {
    //             int s=prices[i]+dp[i+1][1];
    //             int ns=0+dp[i+1][0];
    //             dp[i][buy]=max(s,ns);
    //         }
    //     }
    // }
    // return dp[0][1];

    //space optimization

    vector<int>next(2,0),curr(2,0);
    
    next[0]=prices[n-1];
    next[1]=0;

    for(int i=n-2;i>=0;i--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            if(buy==1)
            {
                int b=-prices[i]+next[0];
                int nb=next[1];
                curr[buy]=max(max(b,nb),0);
            }

            else
            {
                int s=prices[i]+next[1];
                int ns=0+next[0];
                curr[buy]=max(s,ns);
            }
        }
        next=curr;
    }
    return next[1];
}

int main()
{
    int n;cin>>n;

    vector<int> prices(n);

    for(int i=0;i<n;i++)cin>>prices[i];

    cout<<maxProfit(prices);
    return 0;
}
