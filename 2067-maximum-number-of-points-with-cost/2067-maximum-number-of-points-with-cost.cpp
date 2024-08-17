class Solution {
public:
    int m,n;
    long long max(long long a,long long b){
        if(a>b) return a;
        return b;
    }
    long long solve(int row,int col,vector<vector<int>>& points){
        if(row>=m)return 0;
        
        long long res=-1e18;
        for(int c=0;c<n;c++){
            int temp=solve(row+1,c,points)-abs(col-c);
            res=max(res,temp);
        }
        return points[row][col]+res;
    }
    long long memoization(int row,int col,vector<vector<int>>& points,vector<vector<int>>&dp){
        if(row>=m){
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        long long res=-1e18;
        for(int c=0;c<n;c++){
            int temp=memoization(row+1,c,points,dp)-abs(col-c);
            res=max(res,temp);
        }
        return dp[row][col]=points[row][col]+res;
    }
    long long tabulationSolution(vector<vector<int>>& points){
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        
        for(int row=m-1;row>=0;row--){
            for(int col=n-1;col>=0;col--){
                long long res=-1e18;
                for(int c=0;c<n;c++){
                    int temp=dp[row+1][c]-abs(col-c);
                    res=max(res,temp);
                }
                dp[row][col]=points[row][col]+res;
            }
        }
        
        long long result=-1e18;
        for(int c=0;c<n;c++){
            result=max(result,dp[0][c]);
        }
        return result;
    }
    long long optimalTabulation(vector<vector<int>>& points){
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,-1));
        for(int i=0;i<n;i++){ 
            dp[0][i]=points[0][i];
        }
        for(int i=1;i<m;i++){
            vector<long long>left(n),right(n);
            left[0]=dp[i-1][0];
            for(int j=1;j<n;j++){
                left[j]=max(left[j-1]-1,dp[i-1][j]);
            }
    
            right[n-1]=dp[i-1][n-1];
            for(int j=n-2;j>=0;j--){
                right[j]=max(right[j+1]-1,dp[i-1][j]);
            }
            for(int j=0;j<n;j++){
                dp[i][j]=points[i][j]+max(left[j],right[j]);
            }
        }
        long long ans=-1e18;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[m-1][i]);
        }

        return ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        m=points.size(),n=points[0].size();
        long long result=-1e18;
        //Bruteforce recursion
        // for(int c=0;c<n;c++){
        //     long long res=solve(0,c,points);
        //     result=max(result,res);
        // }

        //memoization
        // for(int c=0;c<n;c++){
        //     vector<vector<int>>dp(m,vector<int>(n,-1));
        //     long long res=memoization(0,c,points,dp);
        //     result=max(result,res);
        // }
        

        //tabulation code
        // return tabulationSolution(points); // O(n^3) time limit 

        //optimalTabulation
        return optimalTabulation(points);

        return result;
    }
};