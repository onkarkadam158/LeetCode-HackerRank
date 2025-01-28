class Solution {
public:
    int m,n;
    vector<vector<int>>arr={{-1,0},{1,0},{0,1},{0,-1}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }
    int bfs(int i,int j,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        int res=grid[i][j];
        grid[i][j]=0;
        q.push({i,j});
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            for(auto a:arr){
                int dx=x+a[0],dy=y+a[1];
                if(check(dx,dy) and grid[dx][dy]>0){
                    res+=grid[dx][dy];
                    grid[dx][dy]=0;
                    q.push({dx,dy});
                }
            }
            q.pop();
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    result=max(result,bfs(i,j,grid));
                }
            }
        }
        return result;

    }
};