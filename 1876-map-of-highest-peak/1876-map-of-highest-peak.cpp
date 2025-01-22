class Solution {
public:
    #define pii pair<int,pair<int,int>>
    int m,n;
    vector<vector<int>>dir={{0,-1},{0,1},{-1,0},{1,0}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<m and j<n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m=isWater.size(),n=isWater[0].size();
        queue<pii>que; //{height,{i,j}}
        vector<vector<int>>res(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]){
                    que.push({0,{i,j}});
                    res[i][j]=0;
                }
            }
        }
        while(!que.empty()){
            int size=que.size();
            while(size--){
                auto front=que.front();
                int height=front.first,x=front.second.first,y=front.second.second;
                que.pop();
                for(auto &a:dir){
                    int dx=x+a[0],dy=y+a[1];
                    if(check(dx,dy) and res[dx][dy]==-1){
                        que.push({height+1,{dx,dy}});
                        res[dx][dy]=height+1;
                    }
                }
            }
        }
        return res;
    }
};