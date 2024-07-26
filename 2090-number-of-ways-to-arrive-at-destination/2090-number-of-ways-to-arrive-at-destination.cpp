class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto a:roads){
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        vector<long long>distance(n,1e15),ways(n,0);
        ways[0]=1;
        distance[0]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>que;
        que.push({0,0});
        while(!que.empty()){
            long long currNode=que.top().second;
            long long currDist= que.top().first;
            que.pop();
            for(auto a:adj[currNode]){
                long long newNode=a.first,newDist=a.second;
                if(currDist+newDist < distance[newNode]){
                    distance[newNode]=currDist+newDist;
                    que.push({distance[newNode],newNode});
                    ways[newNode]=ways[currNode]%mod;
                }
                else if((currDist+newDist) == distance[newNode]){
                    ways[newNode]=(ways[newNode]+ways[currNode])%mod;
                }
            }
        }
        // for(auto a:ways)cout<<a<<" ";
        return ways[n-1]%mod;
    }
};