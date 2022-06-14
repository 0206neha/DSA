#include <bits/stdc++.h>
using namespace std;


bool f(int i,int k,vector<int>&a, vector<vector<int>>&dp)
{	if(k==0)return true;
	if(i==0)return a[0]==k;

    if(dp[i][k]!=-1)return dp[i][k];
	int nt=f(i-1,k,a,dp);
	int t=false;
    
	if(a[i]<=k)t=f(i-1,k-a[i],a,dp);
    cout<<"take:"<<t;
    cout<<endl;
    cout<<"not take:"<<nt;
	return dp[i][k]=(t or nt);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
	
	// return f(n-1,k,arr,dp);
    

    // tabulation
    vector<vector<int>>dp(n,vector<int>(k+1,-1));

     for(int i=0;i<n;i++)
        dp[i][0] = 1;

    for(int target=1;target<=k;target++)
        dp[0][target] = arr[0] == target;

    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
            int nt=dp[i-1][k];
	        int t=false;
	        if(arr[i]<=k)t=dp[i-1][k-arr[i]];
            dp[i][k]=(t or nt);
        }
    }

    return dp[n-1][k];

    //space optimization
    // vector<int>prev(k + 1, 0), curr(k+1,0);

    // for(int target=1;target<=k;target++)
    //    prev[target] = arr[0] == target;

    // prev[0] = curr[0] = 1;

    // for(int i=1;i<n;i++){
    //     for(int target=1;target<=k;target++){
    //         int nt = prev[target];
    //         int t = false;
    //         if (arr[i] <= target)
    //             t = prev[target-arr[i]];

    //         curr[target] = (t || nt);
    //     }
    //     prev = curr;
    // }
    // return prev[k];
}

int main()
{
    int n,k;
    cout<<"Enter value for n:";
    cin>>n;
    cout<<"Enter value for k:";
    cin>>k;
    vector<int>arr(n);
    cout<<"Input:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<subsetSumToK(n,k,arr);
    return 0;

}