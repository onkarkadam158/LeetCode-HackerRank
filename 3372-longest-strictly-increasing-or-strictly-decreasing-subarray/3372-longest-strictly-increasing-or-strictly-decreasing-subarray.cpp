class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=i+1;j<n;j++){
                if(nums[j-1]<nums[j]) cnt++;
                else break;
            }
            count=max(count,cnt);
        }

        for(int i=0;i<n;i++){
            int cnt=1;
            for(int j=i+1;j<n;j++){
                if(nums[j-1]>nums[j]) cnt++;
                else break;
            }
            count=max(count,cnt);
        }
        return count;
    }
};