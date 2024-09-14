class Solution {
public:
    int bruteforce(vector<int>&nums){
        int n=nums.size(),result=0,size=0;
        for(int i=0;i<n;i++){
            int temp=nums[i];
            for(int j=i;j<n;j++){
                temp=(temp&nums[j]);
                result=max(result,temp);
            }
        }
        //result has maxi AND of any subarray
        for(int i=0;i<n;i++){
            int temp=nums[i];
            for(int j=i;j<n;j++){
                temp=(temp&nums[j]);
                if(temp==result){
                    size=max(size,j-i+1);
                }
            }
        }
        return size;
    }
    int optimal(vector<int>&nums){
        int res=0;
        for(auto a:nums){
            res=max(res,a);
        }
        int result=1,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1] and nums[i]==res){
                count++;
            }
            else{
                count=1;
            }
            result=max(result,count);
        }
        return result;
    }
    int longestSubarray(vector<int>& nums) {
        // return bruteforce(nums); //TLE O(n^2) time space O(1)

        return optimal(nums);
    }
};