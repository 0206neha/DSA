/*
link-> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
Input: prices = [1,2,3,0,2]
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;
int f(int i, int buy, int n, vector<int>& prices, vector<vector<int>>& dp)
{
    if(i==n-1)
    {
        
            if(buy==1)return 0;
            else return prices[n-1];
    }

    if(dp[i][buy]!=-1)return dp[i][buy];
    //buy

    if(buy==1)
    {
        int b=-prices[i]+f(i+1,0,n,prices,dp);
        int nb=f(i+1,1,n,prices,dp);
        
        return dp[i][buy]=max(max(nb,b),0);
    }
    else
    {
        int s=prices[i];
        if(i+2<=n-1) s+=f(i+2,1,n,prices,dp);
        int ns=f(i+1,0,n,prices,dp);
        return dp[i][buy]=max(s,ns);
    }
}

int maxProfit(vector<int>& prices) 
{
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return f(0,1,n,prices,dp);
}

int main(){
    int n;
    cin>>n;

    vector<int>prices(n);

    for(int i=0;i<n;i++)cin>>prices[i];
    cout<<maxProfit(prices);

    return 0;
}