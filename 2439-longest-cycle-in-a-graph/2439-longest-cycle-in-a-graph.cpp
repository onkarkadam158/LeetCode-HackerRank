class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        int answer=-1;
        for(int node=0;node<n;node++){
            if(!vis[node]){
                unordered_map<int,int>mp;
                int currNode=node;
                int count=1;
                mp[currNode]=count++;
                while(!vis[currNode]){
                    vis[currNode]=1;
                    int nextNode=edges[currNode];
                    if(nextNode==-1) break;
                    if(mp.find(nextNode)!=mp.end()){
                        answer=max(answer,count-mp[nextNode]);
                    }
                    mp[nextNode]=count++;
                    currNode=nextNode;
                }

            }
        }
        return answer;
    }
};