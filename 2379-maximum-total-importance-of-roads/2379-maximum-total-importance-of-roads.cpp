class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>adj(n);
        for(auto a:roads){
            adj[a[0]]++,adj[a[1]]++;
        }
        sort(adj.begin(),adj.end());
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=adj[i]*(i+1);
        }
        return sum;
        
    }
};