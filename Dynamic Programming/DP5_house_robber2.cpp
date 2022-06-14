/*
link -> https://leetcode.com/problems/house-robber-ii/
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected,
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.
i/p->
4
1 2 3 1
o/p->
4
Recursion -> tc->2^n sc->O(n)
Memoization -> tc-> O(n) sc-> O(n) + O(2n)
Tabulation -> tc-> O(n) sc-> O(2n)
Space optimization -> tc->O(n) sc->O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, int stop, vector<int> &arr, vector<int> &dp)
{
    if (i == stop)
        return arr[stop];

    if (dp[i] != -1)
        return dp[i];
    int t = arr[i];
    if (i > stop + 1)
        t += f(i - 2, stop, arr, dp);
    int nt = f(i - 1, stop, arr, dp);
    return dp[i] = max(t, nt);
}

int robber2(int n, vector<int> &arr)
{
    if (n == 1)
        return arr[0];
    //    int t=f(n-1,1,arr);
    //    int nt=f(n-2,0,arr);
    //    return max(t,nt);

    // memoization
    //  vector<int>dp1(n,-1);
    //  vector<int>dp2(n,-1);
    //  int t=f(n-1,1,arr,dp1);
    //  int nt=f(n-2,0,arr,dp2);
    //  return max(t,nt);

    // tabulation
    //  vector<int>dp1(n,0);
    //  vector<int>dp2(n,0);

    // dp1[1]=arr[1];
    // for(int i=2;i<n;i++)
    // {
    //      int t=arr[i];
    //     if (i>2) t+=dp1[i-2];
    //     int nt=dp1[i-1];
    //     dp1[i]=max(t,nt);
    // }

    // dp2[0]=arr[0];
    // for(int i=1;i<n;i++)
    // {
    //     int t=arr[i];
    //     if (i>1) t+=dp2[i-2];
    //     int nt=dp2[i-1];
    //     dp2[i]=max(t,nt);
    // }

    // return max(dp1[n-1],dp2[n-2]);

    // space optimization

    int prev1 = arr[1], prev2 = 0, curr = 0;
    for (int i = 2; i < n; i++)
    {
        int t = arr[i];
        if (i > 2)
            t += prev2;
        int nt = prev1;
        curr = max(t, nt);
        prev2 = prev1;
        prev1 = curr;
    }

    int p1 = arr[0], p2 = 0, curr1 = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int t = arr[i];
        if (i > 1)
            t += p2;
        int nt = p1;
        curr1 = max(t, nt);
        p2 = p1;
        p1 = curr1;
    }

    return max(prev1, p1);
}
int main()
{
    int n;
    cout << "Enter value for n:";
    cin >> n;
    vector<int> arr(n);
    cout << "Input:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a = robber2(n, arr);
    cout << a;
}