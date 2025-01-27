class Solution {
public:
    void dfs(int source,int node,vector<vector<int>>&adj,vector<vector<int>>&res,vector<int>&vis){
        vis[node]=true;
        res[source][node]=true;
        for(auto neighbor:adj[node]){
            if(!vis[neighbor]){
                dfs(source,neighbor,adj,res,vis);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int V=numCourses;
        //creating adjacency list
        vector<vector<int>>adj(V),res(V,vector<int>(V,0));
        for(auto a:prerequisites){
            adj[a[0]].push_back(a[1]);
            res[a[0]][a[1]]=1;
        }
        for(int i=0;i<V;i++){
            vector<int>vis(V,0);
            dfs(i,i,adj,res,vis);
        }
        vector<bool> result;
        for(auto a:queries){
            int i=a[0],j=a[1];
            result.push_back(res[i][j]);
        }

        return result;
    }
};