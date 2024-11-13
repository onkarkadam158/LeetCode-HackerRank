class Solution {
public:
    int m,n;
    void makeRow(vector<vector<int>>& mat,int i){
        for(int j=0;j<n;j++){
            if(mat[i][j])mat[i][j]=(-1e9);
        }
    }
    void makeCol(vector<vector<int>>& mat,int j){
        for(int i=0;i<m;i++){
            if(mat[i][j])mat[i][j]=(-1e9);
        }
    }
    void bruteforce(vector<vector<int>>& mat){
        m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    makeRow(mat,i);
                    makeCol(mat,j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==(-1e9)){
                    mat[i][j]=0;
                }       
            }
        }
    }
    //Solution 2
    void better(vector<vector<int>>& mat){
        m=mat.size(),n=mat[0].size();
        vector<int>row,col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(auto i:row){
            for(int j=0;j<n;j++){
                mat[i][j]=0;
            }
        }

        for(auto j:col){
            for(int i=0;i<m;i++){
                mat[i][j]=0;
            }
        }
    }
    
    //SOlution 3
    void optimal(vector<vector<int>>& mat){
        m=mat.size(),n=mat[0].size();
        int col0=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    if(j!=0)  mat[0][j]=0;
                    else col0=0;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]!=0){
                    if(mat[i][0]==0 or mat[0][j]==0) {
                        mat[i][j]=0;
                    }
                }
            }
        }
        if(mat[0][0]==0) {
            for(int j=0;j<n;j++){
                mat[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<m;i++){
                mat[i][0]=0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        // bruteforce(matrix);//O((n*m)*(n+m)) solution time space O(1)

        // better(matrix);//O((n*m) + 2*(n*m)) solution time space O((n+m))

        optimal(matrix);//O((n*m)) solution time space O(1)
    }
};