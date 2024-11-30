class Solution {
public:
    int bruteforce(vector<int>&nums){
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]!=nums[i+1]) return nums[i];
            }
            else if(i==n-1){
                if(nums[i-1]!=nums[i]) return nums[i];
            }
            else{
                if(nums[i]!=nums[i+1] and nums[i]!=nums[i-1]) return nums[i];
            }
        }
        return 0;
    }
    int bitManipulationSolution(vector<int>& nums){
        int res=0;
        for(auto a:nums) res=res^a;
        return res;
    }
    int singleNonDuplicate(vector<int>& nums) {
        // return bitManipulationSolution(nums);// O(N) solution
        // return bruteforce(nums); //O(N) solution

        // binary search O(logn) solution
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];

        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid-1]!=nums[mid] and nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid%2){
                if(nums[mid]==nums[mid-1])low=mid+1;
                else high=mid-1;
            }
            else{
                if(nums[mid]==nums[mid-1]) high=mid-1;
                else low=mid+1;
            }
        }
        return 0;
    }
};