class Solution {
public:
    int solution1(vector<vector<int>>& edges){
        int node,node1,node2,count1,count2;
        for(int i=0;i<edges.size();i++){
            count1=0;
            count2=0;
            node1=edges[i][0];
            node2=edges[i][1];
            for(int j=0;j<edges.size();j++)
            {
                if(node1==edges[j][0] || node1==edges[j][1])
                    count1++;
                if(node2==edges[j][0] || node2==edges[j][1])
                    count2++;
            }
            if(count1==edges.size())
                {node=node1;break;}
            else if(count2==edges.size())
                {node=node2;break;}
        }
        return node;
    }
    int solution2(vector<vector<int>>& edges){
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        for(int i=0;i<adj.size();i++){
            if(adj[i].size()>1){
                return i;
            }
        }
        return -1;
    }
    int findCenter(vector<vector<int>>& edges) {
        // return solution1(edges);

        return solution2(edges);
    }
};