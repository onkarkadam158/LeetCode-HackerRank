class Solution {
public:
    //Approach 1
    bool cycle(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& dfsvisited){
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(cycle(it,adj,visited,dfsvisited))
                    return true;
            }
            else if(dfsvisited[it]==true){
                return true;
            }
        }
        dfsvisited[node]=0;
        return false;
    }
    bool checkcycleDFS(int num,vector<vector<int>> adj){
        vector<int> dfsvisited(num,0),visited(num,0);
        for(int i=0;i<num;i++){
            if(!visited[i]){
                if(cycle(i,adj,visited,dfsvisited)==true){ 
                    return true;
                }
            } 
        }
        return false;
    }

    //Approach 2
    bool cycleOptimal(int node,vector<vector<int>>& adj,vector<int>& visited){
        visited[node]=2;
        for(auto it: adj[node]){
            if(!visited[it]){
                if(cycleOptimal(it,adj,visited))
                    return true;
            }
            else if(visited[it]==2){
                return true;
            }
        }
        visited[node]=1;
        return false;
    }
    bool checkcycleDFSOptimal(int num,vector<vector<int>> adj){
        vector<int> visited(num,0);
        for(int i=0;i<num;i++){
            if(!visited[i]){
                if(cycleOptimal(i,adj,visited)==true){ 
                    return true;
                }
            } 
        }
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num);
        for(auto a:pre){
            adj[a[1]].push_back(a[0]);
        }    
        //this is using two visited array one is path visited and another visited array
        // if(checkcycleDFS(num,adj)){
        //     return false;
        // }

        //this is using single visited array on which 0 means not vsited 1 means visited and 2 means path + visited
        if(checkcycleDFSOptimal(num,adj)){
            return false;
        }
        return true;
    }
};