class Solution {
public:
    vector<int>solution1(vector<vector<int>>& mat){
        vector<int> res;
        int n=mat.size();
        int m=mat[0].size();
        map<pair<int,int>,int>mp;
        //calculate Row wise min
        for(int i=0;i<n;i++)
        {
            int rowmin=mat[i][0];
            pair<int,int>rowInd={i,0};
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]<rowmin)
                {
                    rowInd={i,j};
                    rowmin=mat[i][j];
                }
            }
            mp[rowInd]++;
        }
        for(int i=0;i<m;i++)
        {
            int colmax=mat[0][i];
            pair<int,int>colInd={0,i};
            for(int j=0;j<n;j++)
            {
                if(mat[j][i]>colmax)
                {
                    colInd={j,i};
                    colmax=mat[j][i];
                }
            }
            mp[colInd]++;
        }
        for(auto a:mp)
            if(a.second==2)
                res.push_back(mat[a.first.first][a.first.second]);
        return res;
    }
    vector<int>solution2(vector<vector<int>>& mat){

        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int mini=mat[i][0];
            for(int j=0;j<m;j++){
                mini=min(mini,mat[i][j]);
            }
            mp[mini]++;
        }
        for(int i=0;i<m;i++){
            int maxi=mat[0][i];
            for(int j=0;j<n;j++){
                maxi=max(maxi,mat[j][i]);
            }
            mp[maxi]++;
        }
        vector<int>res;
        for(auto a:mp){
            if(a.second==2){
                res.push_back(a.first);
            }
        }
        return res;
    }
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        // return solution1(mat);
        return solution2(mat);
    }
};