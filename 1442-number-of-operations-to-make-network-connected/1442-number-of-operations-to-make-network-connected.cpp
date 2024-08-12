class Solution {
public:
    int dfs(vector<vector<int>>& arr,int i,vector<int>& vis){
        vis[i]=1;
        for(int j=0;j<arr[i].size();j++){
            if(!vis[arr[i][j]])
                dfs(arr,arr[i][j],vis);
        }
        return 1;
    } 
    int DFSComponentsSolution(int n, vector<vector<int>>& connections){
        int edges=connections.size();
        if(edges<n-1)
            return -1;
        vector<vector<int>>arr(n);
        int components=0;
        vector<int>vis(n,0);
        for(int i=0;i<edges;i++){//creating adjacency list of given graph
            arr[connections[i][0]].push_back(connections[i][1]);
            arr[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                components+=dfs(arr,i,vis);
            }
        }
        // cout<<components;
        return components-1;
    }
    int getParent(int u,vector<int>&parent){
        if(parent[u]==u) return u;
        return parent[u]=getParent(parent[u],parent);
    }
    int DSUSolution(int n, vector<vector<int>>& connections){
        int edges=connections.size();
        if(edges<n-1)
            return -1;

        vector<int>parent(n,0),size(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto a:connections){
            int u=a[0],v=a[1];
            int ultParentOfu=getParent(u,parent);
            int ultParentOfv=getParent(v,parent);
            if(ultParentOfu!=ultParentOfv){
                if(size[ultParentOfu] < size[ultParentOfv]){
                    parent[ultParentOfu]=ultParentOfv;
                    size[ultParentOfv]+=size[ultParentOfu];
                }
                else{
                    parent[ultParentOfv]=ultParentOfu;
                    size[ultParentOfu]+=size[ultParentOfv];
                }
            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) components++;
        }
        return components-1;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // return DFSComponentsSolution(n,connections);

        return DSUSolution(n,connections);
    }
};



