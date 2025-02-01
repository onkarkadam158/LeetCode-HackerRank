class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n,0),suf(n,0);
        int sum=0,sufSum=0;
        pref[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n-1;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if((pref[i]-suf[i+1])%2==0) count++;
        }

        return count;
    }
};