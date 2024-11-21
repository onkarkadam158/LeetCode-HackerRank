class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int count=0,res=0;
        for(int i=0,j=0;j<n;j++){
            if(nums[j]==0)count++;
            if(count<=1){
                res=max(res,j-i+1);
            }
            else{
                while(i<j and count>1){
                    if(nums[i]==0) count--;
                    i++;
                }
                if(count<=1){
                    res=max(res,j-i+1);
                }
            }
        }
        return res-1;
    }
};