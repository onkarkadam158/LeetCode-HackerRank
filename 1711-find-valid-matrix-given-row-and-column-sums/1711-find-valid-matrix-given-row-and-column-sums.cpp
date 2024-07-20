class Solution {
public:
    void print(vector<vector<int>>&v){
        for(auto &a:v){
            for(auto &x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m=rowSum.size(),n=colSum.size();
        vector<vector<int>>res(m,vector<int>(n,0));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>row,col;
        for(int i=0;i<m;i++){
            if(rowSum[i])row.push({rowSum[i],i});
        }
        for(int i=0;i<n;i++){
            if(colSum[i])col.push({colSum[i],i});
        }
        while(!row.empty() and !col.empty()){
            auto row_ele=row.top(),col_ele=col.top();
            row.pop(),col.pop();
            int i=row_ele.second,j=col_ele.second;
            int temp=min(row_ele.first,col_ele.first);
            res[i][j]=temp;
            if(row_ele.first-temp>0){
                row_ele.first-=temp;
                row.push(row_ele);
            }
            if(col_ele.first-temp>0){
                col_ele.first-=temp;
                col.push(col_ele);
            }
        }
        print(res);
        return res;
    }
};