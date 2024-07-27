class Solution {
public:
    #define pii pair<int,int>
    long long getDistance(int src,int dest, vector<vector<pair<int,int>>>&adj){
        vector<long long>distance(26,1e9);
        distance[src]=0;
        priority_queue<pii,vector<pii>,greater<pii>>que;
        que.push({0,src});
        while(!que.empty()){
            int currNode=que.top().second;
            int currDist=que.top().first;
            que.pop();
            for(auto a:adj[currNode]){
                int newNode=a.first,newDist=a.second;
                if(distance[newNode] > newDist+currDist){
                    distance[newNode]= newDist+currDist;
                    que.push({distance[newNode],newNode});
                }
            }
        }
        if(distance[dest]==1e9) return -1;
        return distance[dest];
    }
    long long DijkstraSolution(string &source, string &target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        vector<vector<pair<int,int>>>adj(26);
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a',v=changed[i]-'a',wt=cost[i];
            adj[u].push_back({v,wt});
        }
        long long sum=0;
        for(int i=0;i<source.size();i++){
            int src=source[i]-'a',dest=target[i]-'a';
           int dist=getDistance(src,dest,adj);
           if(dist==-1) return -1;
           sum+=dist;
        }
        return sum;
    }
    long long FloydWarshallSolution(string &source, string &target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        vector<vector<long long>>matrix(26,vector<long long>(26,1e18));
        for(int i=0;i<26;i++) matrix[i][i]=0;
        for(int i=0;i<original.size();i++){
            long long src=original[i]-'a',dest=changed[i]-'a',wt=cost[i];
            matrix[src][dest]=min(matrix[src][dest],wt);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k] + matrix[k][j]);
                }
            }
        }
        long long sum=0;
        for(int ind=0;ind<source.size();ind++){
            int src=source[ind]-'a',dest=target[ind]-'a';
            if(matrix[src][dest]>=1e18){
                return -1;
            }
            else sum+=matrix[src][dest];
            
        }
        return sum;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // return DijkstraSolution(source,target,original,changed,cost); // give TLE 

        return FloydWarshallSolution(source,target,original,changed,cost); //O(n^3 + original.size() ) n=26
    }
};









