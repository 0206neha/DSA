/*
link-> https://leetcode.com/problems/climbing-stairs/
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps.
 In how many distinct ways can you climb to the top?

Input: n = 3
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, vector<int> &dp)
{
    if(i==0) return 1;

    if(dp[i]!=-1)return dp[i];
    int one=f(i-1,dp);
    int two=0;
    if(i-2>=0)two=f(i-2,dp);

    return dp[i]=one+two;
}


int climbStairs(int n)
{
    vector<int>dp(n+1,-1);
    return f(n,dp);
}

int main()
{
    int n;cin>>n;
    cout<<climbStairs(n);
    return 0;
} 

