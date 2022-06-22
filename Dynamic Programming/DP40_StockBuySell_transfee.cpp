/*
link-> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
*/


#include<bits/stdc++.h>
using namespace std;
int f(int i, int buy, int n, vector<int>& prices, vector<vector<int>>& dp,int fee)
{
    if(i==n-1)
    {
        
            if(buy==1)return 0;
            else return prices[n-1]-fee;
    }

    if(dp[i][buy]!=-1)return dp[i][buy];
    //buy

    if(buy==1)
    {
        int b=-prices[i]+f(i+1,0,n,prices,dp,fee);
        int nb=f(i+1,1,n,prices,dp,fee);
        
        return dp[i][buy]=max(max(nb,b),0);
    }
    else
    {
        int s=prices[i]-fee;
        if(i+1<=n-1) s+=f(i+1,1,n,prices,dp,fee);
        int ns=f(i+1,0,n,prices,dp,fee);
        return dp[i][buy]=max(s,ns);
    }
}

int maxProfit(vector<int>& prices,int fee) 
{
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return f(0,1,n,prices,dp,fee);
}

int main(){
    int n,fee;
    cin>>n>>fee;

    vector<int>prices(n);

    for(int i=0;i<n;i++)cin>>prices[i];
    cout<<maxProfit(prices,fee);

    return 0;
}