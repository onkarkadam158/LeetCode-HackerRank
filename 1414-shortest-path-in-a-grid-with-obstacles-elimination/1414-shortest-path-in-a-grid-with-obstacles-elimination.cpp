class Solution {
public:
    #define ppi pair<int,pair<int,int>>
    #define ppii pair<pair<int,int>,pair<int,int>>
    int m,n;
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }
    int backtrackingSolution(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int steps,int k,vector<vector<vector<int>>>&dp){
        if(i==(m-1) and j==(n-1)){
            if(k>=0) return steps;
            return 1e9;
        }
        if(dp[i][j][steps]!=-1) return dp[i][j][steps]; 
        int res=1e9;
        for(auto a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy) and !vis[dx][dy]){
                vis[dx][dy]=1;
                int temp=1e9 ;
                if(grid[dx][dy]==1 ) {
                    temp=backtrackingSolution(dx,dy,grid,vis,steps+1,k-1,dp);
                }
                else {
                    temp=backtrackingSolution(dx,dy,grid,vis,steps+1,k,dp);
                }
                res=min(res,temp);
                vis[dx][dy]=0;
            }
        }
        return dp[i][j][steps]=res;
    }
    int solution1(vector<vector<int>>& grid, int k){
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        vis[0][0]=1;
        
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(m+n+2,-1)));
        int res= backtrackingSolution(0,0,grid,vis,0,k,dp) ;
        return res==1e9 ? -1:res;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        m=grid.size(),n=grid[0].size();
        // return solution1(grid,k); //backtracking solution exponential time commplexity

        queue<vector<int>>pq; //<steps,obstacleRemaining> , <x,y>
        vector<vector<vector<int>>>vis(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        pq.push({0,0,k});
        vis[0][0][k]=1;
        int steps=0;
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                auto top=pq.front();
                pq.pop();
                
                int obsRem=top[2];
                int x=top[0],y=top[1];
                
                if(x==(m-1) and y==(n-1)) {
                    return steps;
                }
                for(auto& a:dir){
                    int dx=x+a[0],dy=y+a[1];
                    if(check(dx,dy) ){
                        if(grid[dx][dy]==1 and obsRem>0 and !vis[dx][dy][obsRem-1]){        
                            pq.push({dx,dy,obsRem-1});
                            vis[dx][dy][obsRem-1]=1;
                        }
                        else if(grid[dx][dy]==0 and !vis[dx][dy][obsRem]){
                            pq.push({dx,dy,obsRem});
                            vis[dx][dy][obsRem]=1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};