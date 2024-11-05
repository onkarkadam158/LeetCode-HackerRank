class Solution {
public:
    int bruteforce(vector<int>&nums){
        sort(nums.begin(),nums.end());
        int i;
        for( i=0;i<nums.size();i++){
            if(nums[i]!=i)
                break;
        }
        return i;
    }
    int missingNumber(vector<int>& nums) {
        // return bruteforce(nums);

        //optimal 1
        // int n=nums.size();
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        // }
        // return n*(n+1)/2 - sum;

        //optimal 2 
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            res=res^nums[i];
            res=res^i;
        }
        res=res^n;
        return res;
    }
};