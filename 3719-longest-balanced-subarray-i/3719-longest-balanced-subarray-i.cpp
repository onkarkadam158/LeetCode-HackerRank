class Solution {
public:
    int bruteforce(vector<int>&nums){
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp1,mp2;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    mp1[nums[j]]++;
                }
                else {
                    mp2[nums[j]]++;
                }
                if(mp1.size()==mp2.size()){
                    res=max(res,j-i+1);
                }
            }
        }
        return res;
    }
    int longestBalanced(vector<int>& nums) {
        return bruteforce(nums);
    }
};