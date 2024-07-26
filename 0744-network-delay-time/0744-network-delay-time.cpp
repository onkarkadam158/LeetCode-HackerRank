class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto a:times){
            adj[a[0]].push_back({a[1],a[2]});
        }
        queue<pair<int,int>>que;
        que.push({k,0});
        vector<int>distance(n+1,1e9);
        distance[k]=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int currNode= que.front().first;
                int currDist=que.front().second;
                que.pop();
                for(auto neighbor:adj[currNode]){
                    int nnode=neighbor.first,ndist=neighbor.second;
                    if(distance[nnode]>currDist+ndist){
                        distance[nnode]=currDist+ndist;
                        que.push({nnode,distance[nnode]});
                    }
                }
            }
        }
        int result=0;
        for(int i=1;i<n+1;i++) {
            // cout<<distance[i]<<" ";
            if(distance[i]==1e9) return -1;
            else result=max(result,distance[i]);
        }
        return result;
    }
};