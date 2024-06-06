class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int ones=0,zeros=0,n=nums.size();
        vector<int>scores(n+1,0),res;
        for(auto a:nums){
            if(a==0)zeros++;
            else ones++;
        }
        int tzeros=0,tones=0,maxScore=0;
        for(int i=0;i<=n;i++){
            int score=tzeros+ones-tones;
            scores[i]=score;
            maxScore=max(score,maxScore);
            if(i<n and nums[i]==0)tzeros++;
            else tones++;
        }
        for(int i=0;i<=n;i++){
            if(scores[i]==maxScore)res.push_back(i);
        }
        return res;
    }
};