class Solution {
public:
    #define pii pair<int,int>
    int getDistance(vector<vector<pair<int,int>>>&adj,int ind,int n){
        priority_queue<pii,vector<pii>,greater<pii>>que;
        que.push({0,0});
        vector<int>dist(n,1e9);
        dist[0]=0;
        while(!que.empty()){
            int currNode=que.top().second;
            int currDist=que.top().first;
            que.pop();
            if(currNode==(n-1)) return dist[n-1];
            for(auto a:adj[currNode]){
                int newDist=a.second,newNode=a.first;
                if(dist[newNode] > newDist+currDist){
                    dist[newNode]= newDist+currDist;
                    que.push({dist[newNode],newNode});
                }
            }
            
        }
        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1});
        }
        for(auto a:queries){
            int u=a[0],v=a[1];
            adj[u].push_back({v,1});
            int dist=getDistance(adj,0,n);
            res.push_back(dist);
        }
        
        return res;
    }
};