class Solution {
public:
    bool solve(int ind,vector<int>&nums,int target){
        if(target<0) return false;
        if(target==0) return true;
        if(ind>=nums.size()) return false;

        bool taken = solve(ind+1,nums,target-nums[ind]);
        bool notTaken = solve(ind+1,nums,target);

        return taken or notTaken;
    }
    bool memoization(int ind,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target<0) return false;
        if(target==0) return true;
        if(ind>=nums.size()) return false;

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool taken = memoization(ind+1,nums,target-nums[ind],dp);
        bool notTaken = memoization(ind+1,nums,target,dp);

        return dp[ind][target]=(taken or notTaken);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &a:nums)sum+=a;

        if(sum%2) return false;
        // return solve(0,nums,sum/2);

        int n=nums.size();
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1)); 
        return memoization(0,nums,target,dp);
    }
};