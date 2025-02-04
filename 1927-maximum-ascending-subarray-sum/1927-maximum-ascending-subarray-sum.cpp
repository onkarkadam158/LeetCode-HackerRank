class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int sum=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j-1] < nums[j]){
                    sum+=nums[j];
                }
                else {
                    break;
                }
            }
            res=max(res,sum);
        }
        return res;
    }
};