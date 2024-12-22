class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            int size=abs(nums[i])%n;
            if(nums[i]==0) {
                continue;
            }
            else if(nums[i]> 0) {
                res[i]=nums[(i+size+n)%n];
            }
            else{
                res[i]=nums[(i-size+n)%n];
            }
        }

        return res;
    }
};