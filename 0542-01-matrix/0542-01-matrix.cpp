class Solution {
public:
    int m,n;
    vector<vector<int>>arr={{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int i,int j){
        return 0<=i and 0<=j and i<m and j<n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size(),n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0)),res(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    que.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!que.empty()){
            auto front=que.front();
            int x=front.first.first;
            int y=front.first.second;
            int level=front.second;
            for(int k=0;k<4;k++){
                int dx=x+arr[k][0],dy=y+arr[k][1];
                if(check(dx,dy)){
                    if(!vis[dx][dy]){
                        res[dx][dy]=level+1;
                        vis[dx][dy]=1;
                        que.push({{dx,dy},level+1});
                    }
                }
            }
            que.pop();
        }
        return res;
    }
};