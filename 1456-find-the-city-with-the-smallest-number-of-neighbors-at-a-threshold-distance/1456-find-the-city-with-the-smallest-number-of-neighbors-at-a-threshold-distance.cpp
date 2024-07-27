class Solution {
public:
    void print(vector<vector<int>>&v){
        for(auto &a:v){
            for(auto &x:a) cout<<x<<" ";
            cout<<endl;
        }
    }
    int countCityReachableGivenThreshold(int src,int n,vector<vector<pair<int,int>>>&adj,int threshold){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
        vector<int>distance(n,1e9);
        que.push({0,src});
        distance[src]=0;
        while(!que.empty()){
            auto top=que.top();
            int currDist=top.first,currNode=top.second;
            que.pop();
            for(auto a:adj[currNode]){
                int newDist=a.second,newNode=a.first;
                if(distance[newNode] > currDist+newDist){
                    distance[newNode]=(currDist+newDist);
                    que.push({distance[newNode],newNode});
                }
            }
        }
        int count=0;
        for(auto a:distance){
            if(a<=threshold){
                count++;
            }
        }
        return count-1;
    }
    //soultion 1
    int DijkstraSolution(int n, vector<vector<int>>& edges, int distanceThreshold){
        vector<vector<pair<int,int>>>adj(n);
        for(auto a:edges){
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        vector<int>cityReachable(n,0);
        int mini=INT_MAX;
        for(int k=0;k<n;k++){
            int count=countCityReachableGivenThreshold(k,n,adj,distanceThreshold);
            cityReachable[k]=count;
            mini=min(count,mini);
        }
        for(int i=n-1;i>=0;i--){
            if(cityReachable[i]==mini) return i;
        }
        return 0;
    }
    //solution 2
    int FloydWarshallSolution(int n, vector<vector<int>>& edges, int distanceThreshold){
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(auto a:edges){
            int i=a[0],j=a[1],wt=a[2];
            adj[i][j]=wt;
            adj[j][i]=wt;
        }
        for(int i=0;i<n;i++) adj[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]=min(adj[i][j], adj[i][k] + adj[k][j] );
                }
            }
        }
        print(adj);
        int maxCount=n,node=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
               if(i!=j and adj[i][j]<=distanceThreshold){
                    count++;
               }
            }
            if(count<=maxCount){
                maxCount=count;
                node=i;
            }
        }
        return node;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // return DijkstraSolution(n,edges,distanceThreshold);
        return FloydWarshallSolution(n,edges,distanceThreshold);
    }
};


























