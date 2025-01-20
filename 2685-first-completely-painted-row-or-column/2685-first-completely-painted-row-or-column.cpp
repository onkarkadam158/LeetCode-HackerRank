class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>row(m+1,0),col(n+1,0);
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mp[mat[i][j]]={i+1,j+1};
            }
        }
        for(int i=0;i<arr.size();i++){
            int r=mp[arr[i]].first,c=mp[arr[i]].second;
            row[r]++,col[c]++;
            if(row[r]==n or col[c]==m) return i; 
        }
        return 0;
    }
};