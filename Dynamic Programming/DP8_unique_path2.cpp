/*
https://leetcode.com/problems/unique-paths-ii/
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
*/

#include<bits/stdc++.h>
using namespace std;


int f(int i,int j,vector<vector<int>>& obs,vector<vector<int>>&dp)
{
    if(obs[i][j]==1)return 0;
    if(i==0 && j==0)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    int up=0;
    if(i>0)up=f(i-1,j,obs,dp);
    int left=0;
    if(j>0)left=f(i,j-1,obs,dp);

    return  dp[i][j]=left+up;

}

int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n=obs.size();
        int m=obs[0].size();
        if(obs[0][0] == 1 || obs[n-1][m-1] == 1)return 0;
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,obs,dp);

        //tabulation
        // vector<vector<int>>dp(n,vector<int>(m,0));
        
        // dp[0][0]=1;

        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(obs[i][j]==1)dp[i][j]=0;
                
        //         else if(i == 0 and j == 0)
        //         {
        //             dp[i][j] = 1;}
        //         else
        //         {
        //             int up=0;
        //             if(i>0)up=dp[i-1][j];
        //             int left=0;
        //             if(j>0)left=dp[i][j-1];

        //             dp[i][j]=left+up;
        //         }
               
        //     }
        // }

        // return dp[n-1][m-1];

        //space optimization

        vector<int>prev(m,0),curr(m,0);
        
        // for(int j=0;j<m;j++)prev[j]=1;
        // curr[0]=1;

        prev[0]=curr[0]=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obs[i][j]==1)
                curr[j]=prev[j]=0;
                
                else if(i == 0 and j == 0)
                {
                    curr[j]=prev[j] = 1;}
                else
                {
                    int up=0;
                    if(i>0)up=prev[j];
                    int left=0;
                    if(j>0)left=curr[j-1];

                    curr[j]=left+up;
                }
               
            }
            prev=curr;
        }

        return prev[m-1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> obstacle(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>obstacle[i][j];
        }
    }

    cout << uniquePathsWithObstacles(obstacle);
    return 0;
}