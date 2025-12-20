class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        int n=strs.size();
        for(int j=0;j<strs[0].size();j++){
            for(int i=1;i<n;i++){
                if(strs[i-1][j] > strs[i][j]){
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};