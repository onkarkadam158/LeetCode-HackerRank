class Solution {
public:

    bool checkForSafe(int node,vector<vector<int>>& adj, vector<int>&visited, vector<int>&pathVis, vector<int>&res){
        visited[node]=1;
        pathVis[node]=1;
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                if(checkForSafe(neighbor,adj,visited,pathVis,res)) return true;
            }
            else if(pathVis[neighbor]){
                return true;
            }
        }
        pathVis[node]=0;
        res.push_back(node);
        return false;
    }
    vector<int> cycleDetectionSolution(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int>res,visited(n,0),pathVis(n,0);
        for(int node=0;node<n;node++){
            if(!visited[node]){
                checkForSafe(node,adj,visited,pathVis,res);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }

    //solution2
    vector<int> topologicalSortSolution(vector<vector<int>>& adj){
        int n=adj.size();
        //reverse the graph and create its adjacency list and do toposort on it the indegree node==0 are terminal and from these where ver you cna reach are safe nodes
        vector<vector<int>> revadj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                int node=adj[i][j];
                revadj[node].push_back(i);
            }
        }
        vector<int>indegree(n,0),toposort;
        for(auto a:revadj){
            for(auto node:a){
                indegree[node]++;
            }
        }
        queue<int>que;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) que.push(i);
        }
        while(!que.empty()){
            int curr=que.front();
            toposort.push_back(curr);
            que.pop();
            for(auto a:revadj[curr]){
                if(indegree[a]>0){
                    indegree[a]--;
                    if(indegree[a]==0)que.push(a);
                }
            }
        }
        sort(toposort.begin(),toposort.end());
        return toposort;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        // return cycleDetectionSolution(adj);

        return topologicalSortSolution(adj);
    }
};