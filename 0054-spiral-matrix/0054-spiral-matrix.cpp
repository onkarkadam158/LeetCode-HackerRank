class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int max_row=m-1;
        int max_col=n-1;
        int min_row=0;
        int min_col=0;
        int count=0;
        vector<int>res;
        while(max_row>=min_row && min_col<=max_col){
            if(count%4==0){
                for(int i=min_col;i<=max_col;i++)
                    res.push_back(matrix[min_row][i]);
                min_row++;
            }else if(count%4==1){
                for(int i=min_row;i<=max_row;i++)
                    res.push_back(matrix[i][max_col]);
                max_col--;
            } else if(count%4==2){
                for(int i=max_col;i>=min_col;i--)
                    res.push_back(matrix[max_row][i]);
                max_row--;
            } else{
                for(int i=max_row;i>=min_row;i--)
                    res.push_back(matrix[i][min_col]);
                min_col++;
            }
            count++;
        }
        return res;
    }
};