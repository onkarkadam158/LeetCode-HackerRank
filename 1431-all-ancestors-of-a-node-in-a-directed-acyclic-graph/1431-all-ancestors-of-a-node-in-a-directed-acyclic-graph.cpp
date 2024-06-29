class Solution {
public:
    void printadj(vector<vector<int>>&adj){ 
        for(int i=0;i<adj.size();i++){
            cout<<i<<" ";
            for(auto a:adj[i]) cout<<a<<" ";
            cout<<endl;
        }
    }
    void dfs(int parent,int prev,vector<vector<int>>&adj,vector<vector<int>>&result){
        for(auto child:adj[prev]){
            int sz=result[child].size();
            if(sz==0 or result[child][sz-1]<parent){
                result[child].push_back(parent);
                dfs(parent,child,adj,result);
            }
        }
    }
    vector<vector<int>> solution(vector<vector<int>>&adj,int n){
        vector<vector<int>> result(n);
        for(int i=0;i<n;i++){
            dfs(i,i,adj,result);
        }
        return result;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //need adj list for solution so this ones common for all
        vector<vector<int>>adj(n);
        for(auto &a:edges){
            adj[a[0]].push_back(a[1]);
        }
        // printadj(adj);
        return solution(adj,n); // time limit error we do dfs from each node and store that node as an ancestor in all the node we can reach from there(via dfs)
    }
};