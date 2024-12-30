class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,int k,int zero,int one){
        if(ind>k) return 0;
        if(ind==k) return 1;
        int takeZero=solve(ind+zero,k,zero,one);
        int takeOne=solve(ind+one,k,zero,one);
        return takeZero+takeOne;
    }
    int bruteforce(int low,int high,int zero,int one){
        int count=0;
        for(int k=low;k<=high;k++){
            count+=solve(0,k,zero,one);
        }
        return count;
    }
    //solution 2
    
    int solve2(int ind,int low,int high,int zero,int one){
        if(ind>high) return 0;
        int count=0;
        if(low<=ind and ind<=high) count++;
        int takeZero=solve2(ind+zero,low,high,zero,one);
        int takeOne=solve2(ind+one,low,high,zero,one);
        return takeZero + takeOne + count;
    }
    //solution 3
    int memoization(int ind,int low,int high,int zero,int one,vector<int>&dp){
        if(ind>high) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int count=0;
        if(low<=ind and ind<=high) count++;
        int takeZero=memoization(ind+zero,low,high,zero,one,dp)%mod;
        int takeOne=memoization(ind+one,low,high,zero,one,dp)%mod;
        return dp[ind] = (takeZero + takeOne + count)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // return bruteforce(low,high,zero,one);// time limit exceed

        // return solve2(0,low,high,zero,one); //TLE

        //Memoization solution
        vector<int>dp(high+1,-1);
        return memoization(0,low,high,zero,one,dp);
    }
};