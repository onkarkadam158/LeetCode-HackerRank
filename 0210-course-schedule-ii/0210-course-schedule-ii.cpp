class Solution {
public:
    vector<int>toposortSolution(int V,vector<int>&indegree, vector<vector<int>>& adj){
        queue<int>que;
        vector<int>toposort;
        for(int node=0;node<V;node++){
            if(indegree[node]==0){
                que.push(node);
            }
        }
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            toposort.push_back(curr);
            for(auto a:adj[curr]){
                if(indegree[a]>0){
                    indegree[a]--;
                    if(indegree[a]==0){
                        que.push(a);
                    }
                }
            }
        }
        if(toposort.size()<V) return {};
        return toposort;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        //creating adjacency list
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(auto a:prerequisites){
            adj[a[1]].push_back(a[0]);
            indegree[a[0]]++;
        }
        return toposortSolution(V,indegree,adj);
    }
};