/*
link-> https://leetcode.com/problems/longest-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;
int f(int i, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
{

    if (i == n)
        return 0;
    /*
        or if(i==n-1)
        if(prev==0 || nums[n-1]>nums[prev]) return nums[n-1];
        else return 0;
    */

    if (dp[i][prev] != -1)
        return dp[i][prev];

    int nt = f(i + 1, prev, n, nums, dp);
    int t = -1e9;
    if (prev == 0 || nums[i] > nums[prev - 1])
        t = 1 + f(i + 1, i + 1, n, nums, dp);

    return dp[i][prev] = max(nt, t);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // return f(0,0,n,nums,dp);  //index shift for prev is done

    // tabulation

    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    //     for(int prev=0;prev<=n;prev++)dp[n-1][prev]=0;

    //     for(int i=n-1;i>=0;i--)
    //     {
    //         for(int prev=0;prev<=i;prev++)
    //         {
    //             int nt=dp[i+1][prev];
    //             int t=-1e9;
    //             if(prev==0 || nums[i]>nums[prev-1])
    //                 t=1+dp[i+1][i+1];

    //             dp[i][prev]=max(nt,t);
    //         }
    //     }

    //   return dp[0][0];

    // alternate method in n2

    vector<int> lis(n, 1);
    int maxi = 1;
    int pos = 0;

    for (int i = 1; i < n; i++)
    {
        for (int pi = 0; pi < i; pi++)
        {
            if (nums[i] > nums[pi])
            {
                if (lis[pi] + 1 > lis[i])
                {
                    lis[i] = lis[pi] + 1;
                    if (lis[i] > maxi)
                    {
                        maxi = lis[i];
                        pos = i;
                    }
                }
            }
        }
    }

    int len = maxi;
    int prev = -1;
    vector<int> ans;

    while (len > 0)
    {
        if (lis[pos] == len)
        {
            if (ans.size() == 0 || nums[pos] < prev)
            {
                ans.push_back(nums[pos]);
                prev = nums[pos];
                len--;
            }
        }
        pos--;
    }
    reverse(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it << " ";

    cout << endl;
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << lengthOfLIS(nums);

    return 0;
}