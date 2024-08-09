class Solution {
public:
    bool isMagicGrid(int x,int y,vector<vector<int>>& grid,int k){
        unordered_map<int,int>mp;
        for(int i=x;i<x+k;i++){
            int rowSum=0;
            for(int j=y;j<y+k;j++){
               rowSum+=grid[i][j];
            }
            mp[rowSum]++;
        }
        for(int i=y;i<y+k;i++){
            int colSum=0;
            for(int j=x;j<x+k;j++){
                colSum+=grid[j][i];
            }
            mp[colSum]++;
        }
        int diagonalSum=0;
        for(int i=0;i<k;i++){
            diagonalSum+=grid[x+i][y+i];
        }
        mp[diagonalSum]++;
        diagonalSum=0;
        for(int i=0;i<k;i++){
            diagonalSum+=grid[x+i][y+k-1-i];
        }
        mp[diagonalSum]++;
        return (mp.size()==1);
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int result=1;
        for(int k=1;k<=min(m,n);k++){
            bool found=false;
            for(int i=0;i<=m-k;i++){
                for(int j=0;j<=n-k;j++){
                    if(isMagicGrid(i,j,grid,k)){
                        result=k;
                        found=true;
                        break;
                    }
                }
                if(found) break;
            }
        }
        return result;
    }
};