class Solution {
public:
    int bruteforce(int ind,int prev,int n){
        if(ind>n) return 1e9;
        if(ind==n) return 0;

        int copyAndPaste=1e9,paste=1e9; 

        copyAndPaste= 2 + bruteforce(2*ind,ind,n); //copy and paste
        paste= 1 + bruteforce(ind+prev,prev,n); //just paste

        return min(copyAndPaste,paste);
    }
    int memoization(int ind,int prev,int n,vector<vector<int>>&dp){
        if(ind>n) return 1e9;
        if(ind==n) return 0;

        int copyAndPaste=1e9,paste=1e9; 

        copyAndPaste= 2 + memoization(2*ind,ind,n,dp); //copy and paste
        paste= 1 + memoization(ind+prev,prev,n,dp); //just paste

        return min(copyAndPaste,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;

        // return bruteforce(1,1,n)+1;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memoization(1,1,n,dp)+1;
    }
};