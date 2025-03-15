class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());

        while(left<right){

            int mid=(left+right)/2;
            int num=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    num++;
                    i++;
                }
            }
            if(num>=k) right=mid;
            else left=mid+1;
        }
        return left;
    }
};