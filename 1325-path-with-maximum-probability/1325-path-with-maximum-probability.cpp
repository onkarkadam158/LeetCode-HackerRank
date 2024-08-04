class Solution {
public:
    #define pid pair<int,double>
    #define pdi pair<double,int>
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pid>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<pdi>que; //use max heap
        que.push({1.0000,start_node});
        vector<double>distance(n,0);
        distance[start_node]=double(1);
        while(!que.empty()){
            int currNode=que.top().second;
            double currDist=que.top().first;
            que.pop();
            for(auto a:adj[currNode]){
                int newNode=a.first;
                double newDist=a.second;
                if(distance[newNode] < currDist*newDist){
                    distance[newNode]=currDist*newDist;
                    que.push({distance[newNode],newNode});
                }
            }
        }   
        return distance[end_node];
    }
};