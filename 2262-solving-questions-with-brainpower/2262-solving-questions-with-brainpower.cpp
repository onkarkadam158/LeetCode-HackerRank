class Solution {
public:
    int n;
    long long bruteforce(int ind,vector<vector<int>>& questions){
        if(ind>=n) return 0;

        long long take =0,ntake =0;

        take = questions[ind][0]+bruteforce(ind+questions[ind][1]+1,questions);

        ntake = bruteforce(ind+1,questions);

        return max(take , ntake);
    }
    long long memoization(int ind,vector<vector<int>>& questions,vector<long long>&dp){
        if(ind>=n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        long long take =0,ntake =0;

        take = questions[ind][0]+memoization(ind+questions[ind][1]+1,questions,dp);

        ntake = memoization(ind+1,questions,dp);

        return dp[ind]=max(take , ntake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        // return bruteforce(0,questions);

        vector<long long> dp(n+1,-1);
        return memoization(0,questions,dp);
    }
};