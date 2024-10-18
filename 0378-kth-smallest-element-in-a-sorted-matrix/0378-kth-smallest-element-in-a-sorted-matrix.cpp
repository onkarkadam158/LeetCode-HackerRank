class Solution {
public:
    #define ppii pair<int,pair<int,int>>
    int bruteforce(vector<vector<int>>& matrix, int k){
        int n=matrix.size();
        vector<int>res;
        for(auto a:matrix){
            for(auto x:a){
                res.push_back(x);
            }
        }
        sort(res.begin(),res.end());
        return res[k-1];
    }
    int solution1(vector<vector<int>>& matrix, int k){
        int n=matrix.size();
        priority_queue<ppii,vector<ppii>,greater<ppii>>pq;
        for(int i=0;i<n;i++){
            pq.push({matrix[i][0],{i,0}});
        }
        int res=matrix[0][0];
        while(k--){
            auto top=pq.top();
            pq.pop();
            res=top.first;
            int x=top.second.first,y=top.second.second;
            if(y+1<n){
                pq.push({matrix[x][y+1],{x,y+1}});
            }
        }
        return res;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return bruteforce(matrix,k);
        return solution1(matrix,k);
    }
};