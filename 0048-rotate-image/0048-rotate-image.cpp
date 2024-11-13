class Solution {
public:
    void bruteforce(vector<vector<int>>& matrix){
        int n=matrix.size();
        //bruteforce 
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                res[i][j]=matrix[n-1-j][i];
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                matrix[i][j]=res[i][j];
    }
    void rotate(vector<vector<int>>& matrix) {
        // return  bruteforce(matrix); //time O(nm) space O(nm)

        //optimal In place  //time O(nm) space O(1)
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto &row:matrix){
            reverse(row.begin(),row.end());
        }
        
    }
};