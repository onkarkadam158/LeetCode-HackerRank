class Solution {
public:
    int m,n;
    int getHeight(int i,vector<vector<int>>&adj,int k){
        queue<int>que;
        vector<int>vis(k,0);
        que.push(i);
        vis[i]=1;
        int level=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int curr=que.front();
                que.pop();
                for(auto child:adj[curr]){
                    if(!vis[child]){
                        que.push(child);
                        vis[child]=1;
                    }
                }
            }
            level++;
        }
        return level-1;
    }
    int getMinHeight(vector<vector<int>>&adj){
        int ans=0;
        for(int node=0;node<m+n;node++){
            ans=max(ans,getHeight(node,adj,n+m));
        }
        return ans;
    }
    int bruteforce(vector<vector<int>>&edges1,vector<vector<int>>&edges2){
        vector<vector<int>>tree(n+m);
        for(auto a:edges1){
            int u=a[0],v=a[1];
            tree[u].push_back(v); tree[v].push_back(u);
        }
        for(auto a:edges2){
            int u=a[0]+n,v=a[1]+n;
            tree[u].push_back(v); tree[v].push_back(u);
        }
        int ans=m+n;
        for(int node=0;node<n;node++){
            for(int node1=n;node1<m+n;node1++){
                vector<vector<int>>adj=tree;
                adj[node1].push_back(node);
                adj[node].push_back(node1);
                ans=min(ans,getMinHeight(adj));
            }
        }
        return ans;
    }

    int getDiameterInOnePass(vector<vector<int>>&adj,int k){
        queue<int>que;
        vector<int>vis(k,0);
        que.push(0);
        vis[0]=1;
        int lastNode=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int curr=que.front();
                lastNode=curr;
                que.pop();
                for(auto child:adj[curr]){
                    if(!vis[child]){
                        que.push(child);
                        vis[child]=1;
                    }
                }
            }
        }
        int level=0;
        vector<int>vis1(k,0);
        que.push(lastNode);
        vis1[lastNode]=1;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int curr=que.front();
                que.pop();
                for(auto child:adj[curr]){
                    if(!vis1[child]){
                        que.push(child);
                        vis1[child]=1;
                    }
                }
            }
            level++;
        }
        return level;
    }
    int optimal(vector<vector<int>>&edges1,vector<vector<int>>&edges2){

        //creating tree adjacency list from the edges
        vector<vector<int>>tree1(n),tree2(m);
        for(auto a:edges1){
            int u=a[0],v=a[1];
            tree1[u].push_back(v); tree1[v].push_back(u);
        }
        for(auto a:edges2){
            int u=a[0],v=a[1];
            tree2[u].push_back(v); tree2[v].push_back(u);
        }

        int dia1=getDiameterInOnePass(tree1,n);
        int dia2=getDiameterInOnePass(tree2,m);

        // cout<<ceil(dia1/2) <<" "<< ceil(dia2/2)<<"\n";
        // cout<<ceil(dia1) <<" "<< ceil(dia2)<<"\n";

        int center=ceil(dia1/2) + ceil(dia2/2) +1;

        return max(center,max(dia1-1,dia2-1));
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        n=edges1.size()+1;
        m=edges2.size()+1;

        //logic now onwards
        // return bruteforce(edges1,edges2); //time O(n*m*(n+m)*(n+m)) space O(n+m)

        return optimal(edges1,edges2);  //time O((n+m)) space O(n+m)
    }
};