class Solution {
public:
    #define ll long long
    
    ll solve(int ind,int prev,vector<int>& a, vector<int>& b,int n){
        if(ind>=n) return 0;
        
        ll take1=-1e18;
        if(prev!=1) take1=a[ind]+solve(ind+1,0,a,b,n);
        
        ll take2=-1e18;
        if(prev!=0) take2=b[ind]+solve(ind+1,1,a,b,n);
        
        ll take3=solve(ind+1,-1,a,b,n);
        
        return max(take1,max(take2,take3));
    } 
    ll memoization(int ind,int prev,vector<int>& a, vector<int>& b,int n,vector<vector<ll>>&dp){
        if(ind>=n) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        ll take1=-1e15;
        if(prev!=1) take1=a[ind]+memoization(ind+1,0,a,b,n,dp);
        
        ll take2=-1e15;
        if(prev!=0) take2=b[ind]+memoization(ind+1,1,a,b,n,dp);
        
        ll take3=memoization(ind+1,-1,a,b,n,dp);
        
        return dp[ind][prev+1]=max(take1,max(take2,take3));
    }
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<long long>>dp(n+1,vector<ll>(4,-1));
        return memoization(0,-1,a,b,n,dp);
        
    }
};