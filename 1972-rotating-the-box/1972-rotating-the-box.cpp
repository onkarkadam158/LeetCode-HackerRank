class Solution {
public:
        void print(vector<vector<char>>&v){
        for(auto &a:v){
            for(auto &x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size(),n=box[0].size();

        for(auto &row:box){
            int i=n-1,j=n-1;
            while(i>=0 and j>=0){
                if(row[i]=='*'){
                    i--;
                    j=i;
                }
                else if(row[j]=='*'){
                    j--;
                    i=j;
                }
                else if(row[j]=='#'){
                    j--;
                    i--;
                }
                else if(row[i]=='.'){
                    i--;
                }
                else{
                    swap(row[i],row[j]);
                    i--,j--;
                }
            }
            
        }
        // print(box);
        vector<vector<char>>res(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][m-1-i]=box[i][j];
            }
        }
        // print(res);
        
        return res;
    }
};