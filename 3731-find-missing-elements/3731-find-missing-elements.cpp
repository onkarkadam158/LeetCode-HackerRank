class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>res;

        for(int i=1;i<n;i++){
            int prev=nums[i-1]+1,curr=nums[i];
            while(prev<curr){
                res.push_back(prev++);
            }
        }

        return res;
    }
};