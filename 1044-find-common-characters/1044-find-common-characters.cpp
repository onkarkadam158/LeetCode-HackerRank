class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        vector<vector<int>>arr(A.size(),vector<int>(26,0));
        for(int i=0;i<A.size();i++)
            for(int j=0;j<A[i].size();j++)
                arr[i][A[i][j]-97]++;
        
        for(int i=0;i<26;i++){
            int mini=A.size();
            for(int j=0;j<A.size();j++){
                mini=min(mini,arr[j][i]);
            }
            string s="";
            s+=(i+97);
            while(mini--){
                res.push_back(s);
            }
        }
        return res;
    }
};