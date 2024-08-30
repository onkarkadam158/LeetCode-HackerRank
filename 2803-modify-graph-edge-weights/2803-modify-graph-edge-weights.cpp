class Solution {
public: 
    #define pii pair<int,int>
    #define ll long long
    ll getShortestWithoutModify(vector<vector<pii>>& adj,int n,int src,int dest){
        vector<ll> distance(n,1e16);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,src});
        distance[src]=0;
        while(!pq.empty()){
            int currNode=pq.top().second;
            int currDist=pq.top().first;
            pq.pop();
            for(auto a:adj[currNode]){
                int newNode= a.first;
                int newDist= a.second;
                if(currDist+newDist < distance[newNode]){
                    distance[newNode]=currDist+newDist;
                    pq.push({distance[newNode],newNode});
                }
            }
        }
        return distance[dest];
    }
    ll getShortestWithModify(vector<vector<pii>>& adj,int n,int src,int dest){
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,src});
        vector<ll> distance(n,1e16);
        distance[src]=0;
        while(!pq.empty()){
            int currNode=pq.top().second;
            int currDist=pq.top().first;
            pq.pop();
            for(auto a:adj[currNode]){
                int newNode= a.first;
                int newDist= a.second;
                if(currDist+newDist < distance[newNode]){
                    distance[newNode]=currDist+newDist;
                    pq.push({distance[newNode],newNode});
                }
            }
        }
        return distance[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pii>>adj(n);
        for(auto a:edges){
            if(a[2]!=-1){
                adj[a[0]].push_back({a[1],a[2]});
                adj[a[1]].push_back({a[0],a[2]});
            }
        }
        ll dist=getShortestWithoutModify(adj,n,source,destination);
        if(dist<target) return {};
        //modify all the edges of wt=-1 to wt=1 and check if i get shortDist == target from this
        bool flag= (dist==target);
        for(auto& edge:edges){
            if(edge[2]==-1){
                
                edge[2]= flag ? 2*1e9 : 1;
                adj[edge[0]].push_back({edge[1],edge[2]});
                adj[edge[1]].push_back({edge[0],edge[2]});

                if(!flag){
                    int newDist=getShortestWithModify(adj,n,source,destination);

                    if(newDist<=target){
                        flag=true;
                        edge[2]+=(target-newDist);
                    }
                }
            }
        }
        
        if(flag) return edges;
        return {};
    }
};