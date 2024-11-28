class Solution {
public:
    #define pii pair<int,int>
    #define ppii pair<int,pair<int,int>>
    int m,n;
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
        
        priority_queue<ppii,vector<ppii>,greater<ppii>>pq;
        distance[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int dist=top.first;
            int x=top.second.first;
            int y=top.second.second;
            
            for(auto a:dir){
                int dx=x+a[0],dy=y+a[1];
                if(check(dx,dy) and !vis[dx][dy]){
                    if((dist + grid[dx][dy]) < distance[dx][dy]){
                        distance[dx][dy]= (dist + grid[dx][dy]);
                        pq.push({ distance[dx][dy] , {dx,dy} });
                        vis[dx][dy]=1;
                    }
                }
            }
        }
        return distance[m-1][n-1];
    }
};