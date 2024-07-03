class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int res1=nums[n-1-0]-nums[3];
        int res2=nums[n-1-1]-nums[2];
        int res3=nums[n-1-2]-nums[1];
        int res4=nums[n-1-3]-nums[0];
        return min(min(res1,res2),min(res3,res4));
    }
};