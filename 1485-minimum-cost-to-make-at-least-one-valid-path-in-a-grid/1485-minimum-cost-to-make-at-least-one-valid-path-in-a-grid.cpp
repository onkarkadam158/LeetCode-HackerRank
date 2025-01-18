class Solution {
public:
    #define ppi pair<int,pair<int,int>>
    int m,n;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        if(n==1 and m==1) return 0;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int cost=top.first,x=top.second.first,y=top.second.second;
            
            int cell=grid[x][y];
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0],dy=y+dir[i][1];
                if(check(dx,dy)){
                    if(cell!=(i+1)){
                        if((cost+1)<dist[dx][dy]){
                            dist[dx][dy]=cost+1;
                            pq.push({cost+1,{dx,dy}});
                        }
                    }
                    else {
                        if(cost<dist[dx][dy]){
                            dist[dx][dy]=cost;
                            pq.push({cost,{dx,dy}});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};