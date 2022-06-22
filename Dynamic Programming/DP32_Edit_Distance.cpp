/*
link-> https://leetcode.com/problems/edit-distance/
ip->
intention
execution
op->
5
Recursion-> tc->O(3^(n*m)) sc->O(n+m)
Memoization-> tc->O(n*m) sc->O(n+m) + O(n*m)
Tabulation-> tc->O(n*m) sc-> O(n*m)
Space optimization-> tc->O(n*m) sc->O(2*m)
*/

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string a, string b, vector<vector<int>> &dp)
{
    if (i == 0)
        return dp[0][j] = j;
    if (j == 0)
        return dp[i][0] = i;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i - 1] == b[j - 1])
    {
        return dp[i][j] = f(i - 1, j - 1, a, b, dp);
    }
    else
    {
        int insert = 1+f(i, j - 1, a, b, dp);
        int delet = 1+f(i - 1, j, a, b, dp);
        int replace =1+ f(i - 1, j - 1, a, b, dp);

        return dp[i][j] = min(insert, min(delet, replace));
    }
}

int minDistance(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, a, b, dp);
}
int main()
{
    string a, b;
    cin>>a>>b;

    cout<<minDistance(a, b);
    return 0;
}