class Solution {
public: 
    int count=0;
    long long dfs(int node, vector<vector<int>>&adj,int n,vector<int>&values,vector<int>&vis,long long k){
        vis[node]=1;
        long long sum=values[node];
        for(auto neighbor:adj[node]){
            if(!vis[neighbor]){
                sum+=dfs(neighbor,adj,n,values,vis,k);
            }
        }
        
        if((sum%k) == 0) count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // if(k==1) return n;
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int>vis(n,0);
        long long m=k;
        dfs(0,adj,n,values,vis,m);
        return count;
    }
};