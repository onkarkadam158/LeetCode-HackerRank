class Solution {
public:
    bool dfsFromBob(int node,vector<vector<int>>&adj,vector<int>&vis,int time,vector<int>&bobTime){
        vis[node]=1;
        if(node==0)  return true;
        
        for(auto neighbor:adj[node]){
            if(!vis[neighbor]){
                bobTime[neighbor]=time+1;
                if(dfsFromBob(neighbor,adj,vis,time+1,bobTime) ) return true;;
                bobTime[neighbor]=1e8;
            }
        }
        return false;
    }

    void dfsFromAlice(int node,vector<vector<int>>&adj,vector<int>&vis,int time,vector<int>&AliceTime,vector<int>&bobTime,int AliceIncome, int& result,vector<int>& amount){
        vis[node]=1;
        AliceTime[node]=time;
        if(AliceTime[node]==bobTime[node]){
            AliceIncome+=amount[node]/2;
        }
        else if(AliceTime[node]<bobTime[node]){
            AliceIncome+=amount[node];
        }
        if(adj[node].size()==1  and  vis[adj[node][0]]) {
            //leaf node condition
            result=max(result,AliceIncome);
        }
        for(auto neighbor:adj[node]){
            if(!vis[neighbor]){
                dfsFromAlice(neighbor,adj,vis,time+1,AliceTime,bobTime,AliceIncome,result,amount);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<int>bobTime(n,1e8);
        int time=0;
        
        bobTime[bob]=time;
        dfsFromBob(bob,adj,vis,time,bobTime);

        vis.clear();
        vis.resize(n,0);
        
        vector<int>AliceTime(n,0);
        time=0;
        int AliceIncome=0,result=-1e5;
        dfsFromAlice(0,adj,vis,time,AliceTime,bobTime,AliceIncome,result,amount);

        // for(auto a:AliceTime) cout<<a<<" ";
        // cout<<endl;
        // for(auto a:bobTime) cout<<a<<" ";

        return result;
    }
};