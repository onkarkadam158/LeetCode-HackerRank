class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>arr(n,vector<int>(n,0));
        int min_row=0,max_row=n-1,max_col=n-1,min_col=0;
        int num=1;
        int count=0;
        while(max_row>= min_row && max_col>=min_col){
            if(count%4==0){
                for(int i=min_col;i<=max_col;i++)
                    arr[min_row][i]=num++;
                min_row++;
            }else if (count%4==1){
                for(int i=min_row;i<=max_row;i++)
                    arr[i][max_col]=num++;
                max_col--;
            }else if (count%4==2){
                for(int i=max_col;i>=min_col;i--)
                    arr[max_row][i]=num++;
                max_row--;
            }else{
                for(int i=max_row;i>=min_row;i--)
                    arr[i][min_col]=num++;
                min_col++;
            }
            count++;
        }
        return arr;
    }
};