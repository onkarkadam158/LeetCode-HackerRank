class Solution {
public:
    int solve(int ind,vector<int>& nums, int target){
        if(ind==nums.size()){
            return target==0;
        }
        int pos=solve(ind+1,nums,target+nums[ind]);
        int neg=solve(ind+1,nums,target-nums[ind]);
        return (pos+neg);
    }
    // int memoizationString(int ind,vector<int>& nums,string sum, int target,unordered_map<string,int>&dp){
    //     if(ind==nums.size()){
    //         return target==0;
    //     }
    //     if(dp.find(sum)!=dp.end()) return dp[sum];
    //     int pos=memoization(ind+1,nums,sum+"+",target+nums[ind],dp);
    //     int neg=memoization(ind+1,nums,sum+"-",target-nums[ind],dp);
    //     return dp[sum]=(pos+neg);
    // }
    int memoization(int ind,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(ind<0){
            return sum==0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int ntake=memoization(ind-1,nums,sum,dp);
        int take=0;
        if(sum>=nums[ind]) take=memoization(ind-1,nums,sum-nums[ind],dp);
        return dp[ind][sum]=take+ntake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalSum=0;
        for(auto a:nums)totalSum+=a;
        if((totalSum+target)%2 or (totalSum+target)<0) return 0;
        int sum=(totalSum+target)/2;
        //bruteforce recursive 
        // return solve(0,nums,target);

        // string sum="";
        // unordered_map<string,int>dp;
        // return memoizationString(0,nums,sum,target,dp);


        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return memoization(n-1,nums,sum,dp);

    }
};