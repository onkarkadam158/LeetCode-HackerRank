class Solution {
public:
    int bruteforce(vector<int>&nums){
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                res=max(res,abs(sum));
            }
        }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        // return bruteforce(nums); //TLE O(n^2) solution 
    
        int n=nums.size();
        int minSum=0,maxSum=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0) sum=0;
        }
        sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            minSum=min(minSum,sum);
            if(sum>0) sum=0;
        }
        return max(abs(minSum),abs(maxSum));

    }
};