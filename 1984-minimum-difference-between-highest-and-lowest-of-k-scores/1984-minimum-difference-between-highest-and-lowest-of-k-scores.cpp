class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()<2)
            return 0;
        sort(nums.begin(),nums.end());
        int res=INT_MAX;
        for(int i=0;i<=nums.size()-k;i++)
            res=min(res,nums[i+k-1]-nums[i]);
         
        return res;
    }
};