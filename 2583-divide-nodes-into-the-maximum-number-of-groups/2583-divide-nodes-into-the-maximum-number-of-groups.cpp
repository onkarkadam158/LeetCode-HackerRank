class Solution {
public:
    bool isBipartite(int node,vector<vector<int>>&adj,vector<int>&vis,vector<vector<int>>&components){
        queue<pair<int,int>>que;
        que.push({node,0});
        vis[node]=0;
        vector<int>compo;
        compo.push_back(node);
        while(!que.empty()){
            auto front=que.front();
            int curr=front.first,color=front.second;
            que.pop();
            for(auto a:adj[curr]){
                if(vis[a]==-1){
                    vis[a]=!color;
                    que.push({a,vis[a]});
                    compo.push_back(a);
                }
                else if(vis[a]==color){
                    components.push_back(compo);
                    return false;
                }
            }
        }
        components.push_back(compo);
        return true;
    }
    int getBFSlength(int node,vector<vector<int>>&adj,vector<int>&vis){
        int maxLevel=1;
        queue<pair<int,int>>que;
        que.push({node,1});
        vis[node]=1;
        while(!que.empty()){
            auto front=que.front();
            int curr=front.first,level=front.second;
            que.pop();
            for(auto a:adj[curr]){
                if(!vis[a]){
                    que.push({a,level+1});
                    vis[a]=1;
                    maxLevel=max(maxLevel,level+1);
                }
            }
        }
        return maxLevel;
    }
    void printv(vector<vector<int>>&arr){
        for(auto a:arr){
            for(auto x:a){
                cout<<x+1<<" ";
            }
            cout<<endl;
        }
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        int result=0;
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0]-1,v=edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,-1); // if the graph is not bipartite it means we cannot divide the node into buckets
        vector<vector<int>>components;
        for(int i=0;i<n;i++){
            if(vis[i]==-1 and !isBipartite(i,adj,vis,components)){
                return -1;
            }
        }
        printv(components);
        for(auto compo:components){
            int sum=0;
            for(auto i:compo){
                vector<int>visited(n,0);
                int temp=getBFSlength(i,adj,visited);
                sum=max(sum,temp);
            }
            result+=sum;
        }
        return result;
    }
};