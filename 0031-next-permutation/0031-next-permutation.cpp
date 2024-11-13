class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]) {
                ind=i-1;
                break;
            }
        }
        if(ind==-1) {
            reverse(nums.begin(),nums.end());
            return ;
        }
        int num=nums[ind];
        for(int i=n-1;i>ind;i--){
            if(nums[i]>num){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};