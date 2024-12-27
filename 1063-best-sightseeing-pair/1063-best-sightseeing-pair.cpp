class Solution {
public:
    int bruteforce(vector<int>& values) {
        int n=values.size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int score=values[i]+values[j]+i-j;
                result=max(result,score);
            }
        }
        return result;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        // return bruteforce(values);
        int n=values.size();
        int result=0,maxTillNow=values[0];
        for(int i=1;i<n;i++){
            result=max(result,values[i]-i+maxTillNow);
            maxTillNow=max(maxTillNow,values[i]+i);
        }
        return result;
    }
};