class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int j=0;j<m;j++){
            int maxi=grid[0][j];
            for(int i=1;i<n;i++){
                if(grid[i][j]>maxi){
                    maxi=grid[i][j];
                    continue;
                }
                count+=maxi+1-grid[i][j];
                maxi=maxi+1;
            }
        }
        return count;
    }
};