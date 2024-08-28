class Solution {
public:
    vector<vector<int>>arr={{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int i,int j,int m,int n){
        return i>=0 and j>=0 and i<m and j<n;
    }
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid2,vector<pair<int,int>>& island){
        grid2[i][j]=0;
        island.push_back({i,j});
        for(auto a:arr){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy,m,n) and grid2[dx][dy]==1 ){
                dfs(dx,dy,m,n,grid2,island);
            }
        }
    }
    bool check2(vector<pair<int,int>>& island,vector<vector<int>>& grid1){
        for(auto a:island){
            int i=a.first,j=a.second;
            if(grid1[i][j]==0) return false;
        }
        return true;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count=0;
        int m=grid2.size(),n=grid2[0].size();
        vector<vector<int>>vis2(m,vector<int>(n,0));
        vector<vector<pair<int,int>>>islands;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j] and grid1[i][j]){
                    vector<pair<int,int>>island;
                    dfs(i,j,m,n,grid2,island);
                    islands.push_back(island);
                }
            }
        }
        for(auto island:islands){
            if(check2(island,grid1)){
                count++;
            }
        }
        return count;
    }
};