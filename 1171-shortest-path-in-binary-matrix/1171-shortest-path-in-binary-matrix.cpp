class Solution {
public:
    int m,n;
    vector<vector<int>>dir= {{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}};
    bool check(int x,int y){
        return x>=0 and y>=0 and x<m and y<n ;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
            return -1;
        m=grid.size(); n=grid[0].size();
        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0]=1;
        int level=1;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                auto curr=que.front();
                que.pop();
                int x=curr.first,y=curr.second;
                if(x==(m-1) and y==(n-1)){
                    return level;
                }
                for(auto it:dir){
                    int dx=x+it[0],dy=y+it[1];
                    if(check(dx,dy) and grid[dx][dy]==0){
                        grid[dx][dy]=1;
                        que.push({dx,dy});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};