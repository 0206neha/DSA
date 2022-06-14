// print from n to 1

#include<bits/stdc++.h>
using namespace std;


void f(int n)
{
    if(n==1)
    {
        cout<<1;
        return;
    }

    f(n-1);
    cout<<n;
    cout<<endl;
}

int f1(int n){
     
    if(n==1)
    {  
        return 1;
    }
    int sum=n+f1(n-1);
    return sum;
}

int main()
{
    //f(4);
    int a=f1(4);
    cout<<a;
    return 0;
}


class Solution {
public:
    
    
    void f(int n,int target,int sum,vector<vector<int>>&ans,vector<pair<int,int>arr1)
    {
        
        if(n==0)
        {
            //not take
            
            //take
        }
        //not take
        f(n,target,sum,ans,arr1);
            
        
        if(arr1.first<=sum)
        {
        //take
            sum+=arr1.first;
            f(n-1,target,sum,ans,arr1);
            sum-=arr1.first;
        }
    }
    
    void give_count(vector<int>arr,vector<pair<int,int>&arr1)
    {
        unordered_map<int,int>np;
        for(int a:arr)
        {
            np[a]++;
        }
        
        for(int a:np)
        {
            arr1.push_back(a);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<pair<int,int>arr1;
        
        sort(candidates.begin(),candidates.end(),greater<int>())
        give_count(candidates,arr1);
        int n=arr1.size();
        f(n-1,target,0,ans,arr1)
    }
};