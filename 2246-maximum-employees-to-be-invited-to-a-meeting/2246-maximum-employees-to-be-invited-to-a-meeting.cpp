class Solution {
public:
    int n;
    int BFS(int node,vector<vector<int>>&adj,vector<int>&vis){
        queue<int>que;
        vis[node]=1;
        que.push(node);
        int level=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int curr=que.front();
                que.pop();                
                for(auto a:adj[curr]){
                    if(!vis[a]){
                        vis[a]=1;
                        que.push(a);
                    }
                }
            }
            level++;
        }
        return level;
    }
    pair<int,int> getCycleSize(int node,vector<int>& favorite,vector<int>&vis){
        int level=1;
        unordered_map<int,int>mp;
        pair<int,int>res;
        while(!vis[node]){
            vis[node]=1;
            mp[node]=level++;
            int nextNode=favorite[node];
            if(mp.find(nextNode)!=mp.end()){
                res={level-mp[nextNode],nextNode};
            }
            node=nextNode;
        }
        return res;
    }
    void printv(vector<vector<int>>&arr){
        for(auto a:arr){
            for(auto x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    int maximumInvitations(vector<int>& favorite) {
        n=favorite.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            adj[favorite[i]].push_back(i);
        }
        int twoSizeCycle=0,nSizeCycle=0;    
        vector<int>vis(n,0);
        // printv(adj);
        // cout<<"\n\n";
        for(int i=0;i<n;i++){
            if(!vis[i]){
                // cout<<"i="<<i<<"\n";
                auto cycle=getCycleSize(i,favorite,vis);
                int cycleSize=cycle.first,node=cycle.second;
                // cout<<i<<" "<<cycleSize<<"\n";
                if(cycleSize==2){
                    vector<int>visited(n,0);
                    int node1=node,node2=favorite[node];
                    visited[node1]=1;
                    visited[node2]=1;
                    twoSizeCycle+=BFS(node1,adj,visited)+BFS(node2,adj,visited);
                }
                else{
                    nSizeCycle=max(nSizeCycle,cycleSize);
                }
            }
        }
        return max(twoSizeCycle,nSizeCycle);

    }
};