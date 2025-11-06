class Solution {
public:
    void getMinConnectedOnlineDFS(int node,vector<vector<int>>&adj,vector<int>&visited,unordered_map<int,int>&online,int& res){
        visited[node]=1;
        if(online[node]) {
            res=min(res,node);
        }
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                getMinConnectedOnlineDFS(neighbor,adj,visited,online,res);
            }
        }
        return ;
    }
    vector<int> bruteforce(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>result;
        unordered_map<int,int>online;
        for(int i=1;i<=c;i++)online[i]=1;//all stations are online

        //creating adjacency matrix of the grid
        vector<vector<int>>adj(c+1);
        for(auto edge:connections){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(auto query:queries){
            int node=query[1];
            if(query[0]==2){
                online[node]=0;
            }
            else{
                if(online[node]==1) {
                    result.push_back(node);
                    continue;
                }
                vector<int>visited(c+1,0);
                int res=INT_MAX;
                getMinConnectedOnlineDFS(node,adj,visited,online,res);
                result.push_back(res==INT_MAX ? -1: res);
            }

        }

        return result;
    }
    void dfs(int node, vector<vector<int>>&adj,vector<int>&visited,unordered_map<int,int>&node_cp,int componentID,unordered_map<int,set<int>>&mp_st){
        visited[node]=1;
        node_cp[node]=componentID;
        mp_st[componentID].insert(node);
        for(auto neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor,adj,visited,node_cp,componentID,mp_st);
            }
        }
    }
    vector<int> optimal(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>result;
        unordered_map<int,int>node_cp;
        unordered_map<int,set<int>>mp_st;
        //creating adjacency matrix of the grid
        vector<vector<int>>adj(c+1);
        for(auto edge:connections){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //iterating over all components and assigning each nodes a component id
        vector<int>visited(c+1);
        int componentID=1;
        for(int node=1;node<=c;node++){
            if(!visited[node]){
                dfs(node,adj,visited,node_cp,componentID,mp_st);
                componentID++;
            }
        }

        for(auto query:queries){
            int node=query[1];
            int CurrComponentID = node_cp[node];
            if(query[0]==2){
                if(mp_st[CurrComponentID].find(node)!=mp_st[CurrComponentID].end()){
                    mp_st[CurrComponentID].erase(node);
                }
            }
            else{
                int res;
                if(mp_st[CurrComponentID].find(node)!=mp_st[CurrComponentID].end()){
                    res=node;
                }
                else{
                    if(!mp_st[CurrComponentID].empty()){
                        res=*mp_st[CurrComponentID].begin();
                    }
                    else{
                        res=-1;
                    }
                }
                result.push_back(res);
            }

        }
        return result;
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // return bruteforce(c,connections,queries); //TLE


        return optimal(c,connections,queries);
    }
};