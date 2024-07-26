class Solution {
public:
    #define pii pair<int,pair<int,int>> 
    int m,n;
    vector<vector<int>>dir= {{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int x,int y){
        return x>=0 and y>=0 and x<m and y<n ;
    }
    bool isPossible(vector<vector<int>>& heights,int k){
        queue<pair<int,int>>que;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[0][0]=1;
        que.push({0,0});
        while(!que.empty()){
            int x=que.front().first,y=que.front().second;
            if(x==(m-1) and y==(n-1)) return true;
            que.pop();
            for(auto a:dir){
                int dx=x+a[0],dy=y+a[1];
                if(check(dx,dy) and !vis[dx][dy]){
                    int diff=abs(heights[dx][dy]-heights[x][y]);
                    if(diff<=k){
                        que.push({dx,dy});
                        vis[dx][dy]=1;
                    }
                }
            }
        }
        return false;
    }
    int binarySearchApproach(vector<vector<int>>& heights,int m,int n){
        int low=0,high=1e6-1,res=-1;
        cout<<isPossible(heights,6);
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(heights,mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
    //solution 2
    int graphApproach(vector<vector<int>>& heights,int m,int n){
        priority_queue<pii,vector<pii>,greater<pii>>que;
        que.push({0,{0,0}});
        vector<vector<int>>distance(m,vector<int>(n,1e9));
        distance[0][0]=1e9;
        while(!que.empty()){
            auto curr=que.top();
            int dist=curr.first;
            int x=curr.second.first,y=curr.second.second;
            if(x==(m-1) and y==(n-1)) return dist;
            que.pop();
            for(auto it:dir){
                int dx=x+it[0],dy=y+it[1];
                if(check(dx,dy)){
                    int newDist=max(dist,abs(heights[x][y]-heights[dx][dy]));
                    if(newDist < distance[dx][dy]){
                        distance[dx][dy]=newDist;
                        que.push({newDist,{dx,dy}});
                    }
                }
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m=heights.size(),n=heights[0].size();
        // return binarySearchApproach(heights,m,n);

        return graphApproach(heights,m,n);
    }
};
