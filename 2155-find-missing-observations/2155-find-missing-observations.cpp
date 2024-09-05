class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int mRollsSum=0;
        for(auto a:rolls) mRollsSum+=a;
        int totalSum=(m+n)*mean;
        int nRollsSum=totalSum-mRollsSum;

        if(nRollsSum < n) return {};
        if(nRollsSum > 6*n ) return {};
        
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(nRollsSum/n);
        }
        int reminder=nRollsSum%n,i=0;
        while(reminder-- and i<n){
            res[i++]++;
        }
        return res;
    }
};