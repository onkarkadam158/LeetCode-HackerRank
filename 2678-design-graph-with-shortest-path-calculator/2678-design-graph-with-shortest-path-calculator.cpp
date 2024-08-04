class Graph {
public:
    #define pii pair<int,int>
    vector<vector<pii>>adj;
    int n;
    Graph(int N, vector<vector<int>>& edges) {
        n=N;
        vector<vector<pii>>tadj(n);
        for(auto a:edges){
            int u=a[0],v=a[1],d=a[2];
            tadj[u].push_back({v,d});
        }
        adj=tadj;
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0],v=edge[1],d=edge[2];
        adj[u].push_back({v,d});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pii,vector<pii>,greater<pii>>que;
        que.push({0,node1});
        vector<int>dist(n,1e9);
        dist[node1]=0;
        while(!que.empty()){
            int currNode=que.top().second;
            int currDist=que.top().first;
            que.pop();
            for(auto a:adj[currNode]){
                int newNode=a.first,newDist=a.second;
                if(dist[newNode]> currDist+newDist){
                    dist[newNode]=currDist+newDist;
                    que.push({dist[newNode],newNode});
                }
            }
        }
        for(auto &a:dist){
            if(a==1e9)a=-1;
        }
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */