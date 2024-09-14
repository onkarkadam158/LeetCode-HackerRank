class Solution {
public:
    int n,m;
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }
    bool solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis, int health,vector<vector<vector<int>>>&dp){
        if(i==(m-1) and j==(n-1)){
            return health>=1;
        }
        if(health<1) return false;
        if(dp[i][j][health]!=-1) return dp[i][j][health];
        for(auto a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy) and !vis[dx][dy]){
                bool temp;
                vis[dx][dy]=1;
                temp = solve(dx,dy,grid,vis,health-grid[dx][dy],dp);
                if(temp) return dp[i][j][health]=true;
                vis[dx][dy]=0;
            }
        }
        return dp[i][j][health]=false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(health+1,-1)));
        
        return solve(0,0,grid,vis,health-grid[0][0],dp);
    }
};