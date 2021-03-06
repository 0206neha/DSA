#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can climb k steps
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/
int helper(int i, vector<int> &cost, vector<int> &dp, int k)
{
    if (i == 0)
        return cost[0];
    if (i == 1)
        return cost[1];

    if (dp[i] != -1)
        return dp[i];

    int mini = 1e9;
    for(int step=1;step<=k;step++){
        int store = 1e9;
        if(i>=step)store = helper(i-step, cost, dp, k);
        mini = min(mini, store);
    }
    return dp[i] = cost[i] + mini;
}

int min_cost(vector<int> &cost, int k)
{
    int n = cost.size();
    cost.push_back(0);

    // memoization
    // vector<int> dp(n + 1, -1);
    // int ans = helper(n, cost, dp, k);
    // cost.pop_back();
    // return ans;

    //tabulation
    int mini = 1e9;
    vector<int> dp(n + 1, 0);

    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<=n;i++)
    {
        for(int step=1;step<=k;step++){
        int store = 1e9;
        if(i>=step)store =dp[i-step];
        mini = min(mini, store);
    }
    dp[i] = cost[i] + mini;
    }
    int ans = dp[n];
    cost.pop_back();
    return ans;

}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout<<min_cost(cost, k);
    return 0;
}