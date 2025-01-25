class Solution {
public:
    int getSum(vector<int>& nums,int start,int i){
        int sum=0;
        for(int j=start;j<=i;j++){
            sum+=nums[j];
        }
        return sum;
    }
    int subarraySum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int start=max(0,i-nums[i]);
                sum+=getSum(nums,start,i);
        }
        return sum;
    }
};