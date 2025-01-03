class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long int>pref,suff(n,0);
        long long int left=0,right=0;
        for(int i=0;i<n;i++){
            left+=nums[i];
            right+=nums[n-1-i];
            pref.push_back(left);
            suff[n-1-i]=right;
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if(pref[i]>=suff[i+1])
                count++;
        }
        return count;
    }
};