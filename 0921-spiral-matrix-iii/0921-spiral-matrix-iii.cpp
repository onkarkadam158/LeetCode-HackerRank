class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>res;
        int count=0;
        int row_op=1;
        int col_op=1;
        res.push_back({rStart,cStart});
        int temp=0;
        while(res.size()<rows*cols){
            if(count%4==0){
                for(int i=0;i<col_op;i++){
                    cStart++;
                    if(rStart<rows && cStart<cols && rStart>=0 && cStart>=0)
                        res.push_back({rStart,cStart});
                }
                col_op++;
            }
            else if(count%4==1){
                for(int i=0;i<row_op;i++){
                    rStart++;
                    if(rStart<rows && cStart<cols && rStart>=0 && cStart>=0)
                        res.push_back({rStart,cStart});
                }
                row_op++;
            }
            else if(count%4==2){
                for(int i=0;i<col_op;i++){
                    cStart--;
                    if(rStart<rows && cStart<cols && rStart>=0 && cStart>=0)
                        res.push_back({rStart,cStart});
                }
                col_op++;
            }
            else{
                for(int i=0;i<row_op;i++){
                    rStart--;
                    if(rStart<rows && cStart<cols && rStart>=0 && cStart>=0)
                        res.push_back({rStart,cStart});
                }
                row_op++;
            }
            count++;
        }
        return res;
    }
};