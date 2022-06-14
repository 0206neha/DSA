#include <bits/stdc++.h>
using namespace std;

//  Input: N = 2, W = 3
// val[] = {1, 1}
// wt[] = {2, 1}
// Output: 3
int f(int i, int w, int val[], int wt[], vector<vector<int>> &dp)
{
    if (w == 0)
        return 0;

    if (i == 0)
    {
        if (wt[0] <= w)
        {
            int a = w / wt[0];
            return a * val[0];
        }

        else
            return 0;
    }

    if (dp[i][w] != -1)
        return dp[i][w];
    int nt = f(i - 1, w, val, wt, dp);

    int t = -1e9;
    if (wt[i] <= w)
        t = val[i] + f(i, w - wt[i], val, wt, dp);

    return dp[i][w] = max(t, nt);
}

int knapSack(int n, int w, int val[], int wt[])
{
    // vector<vector<int>>dp(n,vector<int>(w+1,-1));
    // return f(n-1,w,val,wt,dp);

    // tabulation

    // vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    // for (int we = 0; we <= w; we++)
    // {
    //     if (wt[0] <= we)
    //     {
    //         int a = we / wt[0];
    //         dp[0][we] = a * val[0];
    //     }

    //     else
    //         dp[0][we] = 0;
    // }

    // for (int i = 0; i < n; i++)
    //     dp[i][0] = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int we = 1; we <= w; we++)
    //     {
    //         int nt = dp[i - 1][we];

    //         int t = -1e9;
    //         if (wt[i] <= we)
    //             t = val[i] + dp[i][we - wt[i]];

    //         dp[i][we] = max(t, nt);
    //     }
    // }

    // return dp[n-1][w];

    //space optimization


    vector<int>prev(w + 1, 0),curr(w+1,0);

    for (int we = 0; we <= w; we++)
    {
        if (wt[0] <= we)
        {
            int a = we / wt[0];
            prev[we] = a * val[0];
        }

        else
            prev[we] = 0;
    }

    
        prev[0]=curr[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int we = 1; we <= w; we++)
    
        {   int nt = prev[we];
            int t = -1e9;

            if (wt[i] <= we)
                t = val[i] + curr[we - wt[i]];

            curr[we] = max(t, nt);
        }
        prev=curr;
    }

       return prev[w];
}

int main()
{
    int n, w;
    cout << "Enter values for n & w:";
    cin >> n >> w;

    int val[n], wt[n];
    cout << "Input:";

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << knapSack(n, w, val, wt);
    return 0;
}