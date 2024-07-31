class Solution {
public:
    int n;
    int solve(int ind,int height,int width,int maxWidth,vector<vector<int>>& books){
        if(ind>=n){
            return height;
        }
        int take=1e9,nottake=1e9;
        if(width+books[ind][0]<=maxWidth){
            take=solve(ind+1,max(height,books[ind][1]),width+books[ind][0],maxWidth,books);
        }
        nottake=height+solve(ind+1,books[ind][1],books[ind][0],maxWidth,books);
        
        return min(take,nottake);
    }
    int memoization(int ind,int height,int width,int maxWidth,vector<vector<int>>& books,vector<vector<int>>&dp){
        if(ind>=n){
            return height;
        }
        int take=1e9,nottake=1e9;
        if(dp[ind][width]!=-1) return dp[ind][width];
        if(width+books[ind][0]<=maxWidth){
            take=memoization(ind+1,max(height,books[ind][1]),width+books[ind][0],maxWidth,books,dp);
        }
        nottake=height+memoization(ind+1,books[ind][1],books[ind][0],maxWidth,books,dp);
        
        return dp[ind][width]=min(take,nottake);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        // return solve(0,0,0,shelfWidth,books);

        vector<vector<int>>dp(n,vector<int>(1e3+1,-1));
        return memoization(0,0,0,shelfWidth,books,dp);
    }
};