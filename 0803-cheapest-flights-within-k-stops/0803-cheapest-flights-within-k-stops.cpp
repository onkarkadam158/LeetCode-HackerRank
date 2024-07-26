class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto a:flights){
            adj[a[0]].push_back({a[1],a[2]});
        }
        vector<int>distance(n+1,1e9);
        queue<pair<int,int>>que;
        que.push({src,0});
        distance[src]=0;
        int level=0;
        while(!que.empty() and level<(k+1)){
            int size=que.size();
            while(size--){
                int currNode=que.front().first;
                int dist=que.front().second;
                que.pop();
                for(auto a:adj[currNode]){
                    int neighbor=a.first,ndist=a.second;
                    if(distance[neighbor] > (dist + ndist)){
                        distance[neighbor]=dist+ndist;
                        que.push({neighbor,dist+ndist});
                    }
                }
            }
            level++;
        }
        if(distance[dst]==1e9) return -1;
        return distance[dst];
    }   
};