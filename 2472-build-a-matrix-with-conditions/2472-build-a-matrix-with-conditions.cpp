class Solution {
public:
    void doToposort(vector<int>&toposort,vector<vector<int>>&arr,int n,int k){
        vector<vector<int>>adj(k+1);
        for(auto a:arr){
            adj[a[0]].push_back(a[1]);
        }
        vector<int>indegree(k+1,0);
        for(auto a:adj){
            for(auto node:a){
                indegree[node]++;
            }
        }
        queue<int>que;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0) que.push(i);
        }
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            toposort.push_back(curr);
            for(auto near:adj[curr]){
                if(indegree[near]>0){
                    indegree[near]--;
                    if(indegree[near]==0){
                        que.push(near);
                    }
                }
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>res(k,vector<int>(k,0));
        int n=rowConditions.size(),m=colConditions.size();

        vector<int>rowtoposort,coltoposort;
        doToposort(rowtoposort,rowConditions,n,k);
        doToposort(coltoposort,colConditions,m,k);
        if(rowtoposort.size()<k or coltoposort.size()<k) return {};
        
        for(int i=0;i<k;i++){
            int num=rowtoposort[i];
            for(int j=0;j<k;j++){
                if(coltoposort[j]==num){
                    res[i][j]=num;
                    break;
                }
            }
        }
        return res;
    }
};



















