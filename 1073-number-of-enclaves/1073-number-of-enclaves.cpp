class Solution {
public:
    int m,n;
    vector<vector<int>>arr{{0,0},{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }
    bool checkNotonBoundry(int i,int j){
        return i!=0 and j!=0 and i!=m-1 and j!=n-1;
    }
    int bfs(vector<vector<int>> &grid,int i,int j,bool &toCount){
        queue<pair<int,int>>que;
        que.push({i,j});
        int cntNotBoundry=0;
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            for(int k=0;k<5;k++){
                int dx=x+arr[k][0],dy=y+arr[k][1];
                if(check(dx,dy) and grid[dx][dy]==1){
                    grid[dx][dy]=0;
                    if(checkNotonBoundry(dx,dy)){cntNotBoundry++;}
                    else{
                        toCount=false;
                    }
                    que.push({dx,dy});
                }
            }
        }
        return cntNotBoundry;
    }
    int dfs(vector<vector<int>> &grid,int i,int j,bool &toCount){

        int cells=0;
        for(auto &a:arr){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy) and grid[dx][dy]){
                grid[dx][dy]=0;
                if(!checkNotonBoundry(dx,dy)) toCount=false;
                cells+=dfs(grid,dx,dy,toCount)+1;
            }
        }
        return cells;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bool toCount=true;
                    // int temp=bfs(grid,i,j,toCount);
                    int temp=dfs(grid,i,j,toCount);
                    if(toCount){count+=temp;}
                }
            }
        }
        return count;
    }
};