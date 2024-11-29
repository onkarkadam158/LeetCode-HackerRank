class Solution {
public:
    #define pii pair< pair<int,int>,pair<int,int>>
    int m,n;
    vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }
    int minTimeToReach(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[0][0]=1;
        pq.push({ {0,0},{0,0}});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int time=top.first.first,ind=top.first.second;
            int x=top.second.first,y=top.second.second;
            if(x==(m-1) and y==(n-1)) return time;
            for(auto a:dir){
                int dx=x+a[0],dy=y+a[1];
                if(check(dx,dy) and !vis[dx][dy]){
                    int tempTime=max(1+time + ind,grid[dx][dy]+1+ind);
                    pq.push({{tempTime,!ind},{dx,dy}});
                    vis[dx][dy]=1;
                }
            }
        }
        return 1e9;
    }
};