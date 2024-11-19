class Solution {
public:
    int bruteforce(vector<int>& nums){
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
    int maxSubArray(vector<int>& nums) {
        // return bruteforce(nums);
        int maxi=INT_MIN,res=0;
        for(int i=0;i<nums.size();i++){
            res+=nums[i];
            maxi=max(res,maxi);
            if(res<0)
                res=0;                
        }
        return maxi;
    }
};