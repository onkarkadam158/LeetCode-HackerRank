class Solution {
public:
    #define pii pair<int,pair<int,int>>
    int n,m;
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }
    //solution 1
    int bruteforce(vector<vector<int>>& grid){
        m=grid.size(),n=grid[0].size();
        queue<pii>que;
        que.push({0,{0,0}});
        while(!que.empty()){
            auto front=que.front();
            que.pop();
            int steps=front.first;
            int x=front.second.first;
            int y=front.second.second;
            if(x==m-1 and y==n-1) return steps;
            for(auto a:dir){
                int dx=x+a[0],dy=y+a[1];
                if(check(dx,dy) and (steps+1)>=grid[dx][dy]){
                    que.push({steps+1,{dx,dy}});
                }
            }
        }
        return -1;
    }
    
    int optimal(vector<vector<int>>& grid){
        m=grid.size(),n=grid[0].size();
        if(grid[1][0] > 1 and grid[0][1]>1) return -1;
        priority_queue<pii,vector<pii>,greater<pii>>que;
        vector<vector<int>>vis(m,vector<int>(n,0));
        que.push({0,{0,0}});
        vis[0][0]=1;
        while(!que.empty()){
            auto front=que.top();
            que.pop();
            int steps=front.first;
            int x=front.second.first;
            int y=front.second.second;
            if(x==m-1 and y==n-1) return steps;
            for(auto a:dir){
                int dx=x+a[0],dy=y+a[1];
                if(check(dx,dy) and !vis[dx][dy]){
                    if((steps+1)>=grid[dx][dy]){
                        que.push({steps+1,{dx,dy}});
                    }
                    else if((grid[dx][dy]-steps)%2==0){
                        que.push({grid[dx][dy]+1,{dx,dy}});
                    }
                    else{
                        que.push({grid[dx][dy],{dx,dy}});
                    }
                    vis[dx][dy]=1;
                }
            }
        }
        return -1;
    }
    int minimumTime(vector<vector<int>>& grid) {
        // return bruteforce(grid);

        return optimal(grid);
    }
};