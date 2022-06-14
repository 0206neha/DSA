/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
Input: k = 2, prices = [2,4,1]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i,int buy,int k,int n,vector<int>&prices,vector<vector<vector<int>>>&dp)
{
    if(k==0)return 0;

    if(i==n-1)
    {
        if(buy==1)return 0;
        else return prices[i];
    }

    if(dp[i][buy][k]!=-1)return dp[i][buy][k];

    //buy
    if(buy==1)
    {
        int b=-prices[i]+f(i+1,0,k,n,prices,dp);
        int nb=f(i+1,1,k,n,prices,dp);
        return dp[i][buy][k]=max(max(b,nb),0);
    }

    else
    {
        int s=+prices[i]+f(i+1,1,k-1,n,prices,dp);
        int ns=0+f(i+1,0,k,n,prices,dp);
        return dp[i][buy][k]=max(s,ns);
    }
}

int maxProfit(vector<int>& prices,int k) 
{
    int n=prices.size();
    
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2, vector<int>(k + 1, -1)));
    // return f(0,1,k,n,prices,dp);


    //tabulation

    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    // for (int buy = 0; buy <= 1; buy++)
    // {
    //     for (int trans = 1; trans <= 2; trans++)
    //     {
    //         if (buy == 1){
    //             dp[n-1][buy][trans] = 0;
          
    //         }
    //         else{
               
    //             dp[n - 1][buy][trans] = prices[n - 1];
    //         }
    //     }
    // }

    // for(int i=0;i<n;i++){
    //     for(int buy=0;buy<=1;buy++){
    //         dp[i][buy][0] = 0;
    //     }
    // }

    


    // for(int i=n-2;i>=0;i--){
    //     for(int buy=0;buy<=1;buy++){
    //         for(int trans=k;trans>=1;trans--){
    //             if (buy == 1)
    //             {
    //                 int b = -prices[i] + dp[i+1][0][trans];
    //                 int nb = 0 + dp[i + 1][1][trans];

    //                 dp[i][buy][trans] = max(max(b, nb), 0);
    //             }
    //             else
    //             {
    //                 // sell
    //                 int s = +prices[i] + dp[i + 1][1][trans-1];
    //                 int ns = 0 + dp[i + 1][0][trans];

    //                 dp[i][buy][trans] = max(s, ns);
    //             }
    //         }
    //     }
    // }

    // return dp[0][1][k];

    //space optimization

    vector<vector<int>>next(2, vector<int>(k + 1, 0)),curr(2, vector<int>(k + 1, 0));

    for (int buy = 0; buy <= 1; buy++)
    {
        for (int trans = 1; trans <= 2; trans++)
        {
            if (buy == 1){
                next[buy][trans] = 0;
          
            }
            else{
               
                next[buy][trans] = prices[n - 1];
            }
        }
    }

    
        for(int buy=0;buy<=1;buy++){
            next[buy][0] = curr[buy][0] = 0;
        }

    


    for(int i=n-2;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int trans=k;trans>=1;trans--){
                if (buy == 1)
                {
                    int b = -prices[i] + next[0][trans];
                    int nb = 0 + next[1][trans];

                    curr[buy][trans] = max(max(b, nb), 0);
                }
                else
                {
                    // sell
                    int s = +prices[i] + next[1][trans-1];
                    int ns = 0 + next[0][trans];

                    curr[buy][trans] = max(s, ns);
                }
            }
        }
        next=curr;
    }

    return next[1][k];
}

int main()
{
    int n;cin>>n;
    int k;cin>>k;
    vector<int> prices(n);

    for(int i=0;i<n;i++)cin>>prices[i];

    cout<<maxProfit(prices,k);
    return 0;
}
