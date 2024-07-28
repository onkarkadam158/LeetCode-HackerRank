class Solution {
public:
    #define pii pair<int,int>
    int miniEdgesToCross(int n,vector<vector<int>>&adj){
        vector<int>vis(n,0);
        queue<int>que;
        que.push(0);
        vis[0]=1;
        int level=1;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int curr=que.front();
                que.pop();
                if(curr==n) return level;
                for(auto a:adj[curr]){
                    if(!vis[a]){
                        que.push(a);
                        vis[a]=1;
                    }
                }
            }
            level++;
        }
        return level;
    }
    bool isPossible1(int n,vector<vector<int>>&adj,int k){
        queue<pair<int,pii>>que;
        que.push({1,{-1,1}}); //node,parent,level
        while(!que.empty()){
            int curr=que.front().first;
            int parent=que.front().second.first;
            int level=que.front().second.second;
            que.pop();
            if(curr==n and level==k) return true;
            for(auto a:adj[curr]){
                if(a!=parent and level<k){
                    que.push({a,{curr,level+1}});
                }
            }
        }
        return false;
    }    
    int getSecondMinPathLen(int n,vector<vector<int>>&adj){
        queue<int>que;
        que.push(n-1); 
        vector<int>dist(n,1e9);
        dist[n-1]=0;
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            for(auto a:adj[curr]){
                if(dist[a]==1e9){
                    dist[a]=dist[curr]+1;
                    que.push(a);
                }
            }
        }
        // for(auto a:dist)cout<<a<<" ";
        int secondMinPathLen = dist[0]+2;
        que.push(0);
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            for(auto a:adj[curr]){
                if(dist[a]==dist[curr]){
                    return secondMinPathLen-1;
                }
                else if(dist[a]==(dist[curr]-1)){
                    que.push(a);
                }
            }
        }
        return secondMinPathLen;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto a:edges){
            adj[a[0]-1].push_back(a[1]-1);
            adj[a[1]-1].push_back(a[0]-1);
        }
        // int k=miniEdgesToCross(n,adj);
        
        int secondMinPathLen=getSecondMinPathLen(n,adj);

        int answer=0;   
        for(int i=0;i<secondMinPathLen;i++){
            if((answer/change)%2==1)
                answer=(answer/change +1)*change;
            answer+=time;
        }
        return answer;
    }
};