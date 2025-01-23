class Solution {
public:
    int m,n;
    int check(int i,int j){
        return i>=0 and i<m and j>=0 and j<n;
    }
    vector<vector<int>>arr={{-1,0},{1,0},{0,-1},{0,1}}; 
    int bfs(vector<vector<int>>& grid,int i,int j){
        queue<pair<int,int>>que;
        que.push({i,j});
        grid[i][j]=0;
        int cnt=1;
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            for(int k=-n+1;k<n;k++){
                int dy=y+k;
                if(check(x,dy) and grid[x][dy]){
                    grid[x][dy]=0;
                    que.push({x,dy});
                    cnt++;
                }
            }
            for(int k= -m+1;k<m;k++){
                int dx=x+k;
                if(check(dx,y) and grid[dx][y]){
                    grid[dx][y]=0;
                    que.push({dx,y});
                    cnt++;
                }
            }
            que.pop();
        }
        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int temp=bfs(grid,i,j);
                    if(temp>1) count+=temp;
                }
            }
        }
        return count;
    }
};