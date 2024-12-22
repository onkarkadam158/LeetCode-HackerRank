class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            double prev=nums[i],mid=nums[i+1],nxt=nums[i+2];
            if((prev+nxt) == (mid/2)) count++;
        }
        return count;
    }
};