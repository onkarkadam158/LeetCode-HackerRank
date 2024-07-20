class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        vector<vector<int>>res(2,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            if(colsum[j]==2){
                res[0][j]=1,res[1][j]=1;
                colsum[j]=0;
                upper--,lower--;
            }
        }
        for(int j=0;j<n;j++){
            if(upper and colsum[j]){
                res[0][j]=1;
                colsum[j]--,upper--;
            }
            else if(lower and colsum[j]){
                res[1][j]=1;
                colsum[j]--,lower--;
            }
        }
        for(auto a:colsum)if(a!=0) return {};
        if(upper or lower) return {};
        return res;
    }
};