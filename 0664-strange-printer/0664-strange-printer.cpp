class Solution {
public:
    int bruteforce(int left,int right,string& s){
        if(left>right) return 0;
        if(left==right) return 1;

        //print start all 
        int i=left+1;
        while(i<=right and s[i]==s[left]) i++;
        int start=1+bruteforce(i,right,s);

        int end=1e9;
        for(int j=i;j<=right;j++){
            if(s[j]==s[left]){
                int temp=bruteforce(i,j-1,s)+bruteforce(j,right,s);
                end=min(temp,end);
            }
        }
        return min(start,end);
    }
    int memoization(int left,int right,string& s,vector<vector<int>>&dp){
        if(left>right) return 0;
        if(left==right) return 1;

        if(dp[left][right]!=-1) return dp[left][right];
        //print start all 
        int i=left+1;
        while(i<=right and s[i]==s[left]) i++;
        int start=1+memoization(i,right,s,dp);

        int end=1e9;
        for(int j=i;j<=right;j++){
            if(s[j]==s[left]){
                int temp=memoization(i,j-1,s,dp)+memoization(j,right,s,dp);
                end=min(temp,end);
            }
        }
        return dp[left][right]=min(start,end);
    }
    int strangePrinter(string s) {
        int n=s.size();

        // return bruteforce(0,n-1,s);

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memoization(0,n-1,s,dp);

    }
};