class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0,ind=0;
        for(int i=0;i<n-1;i++){
            int up=upper_bound(nums.begin()+ind+1,nums.end(),nums[i])-nums.begin();
            if(up!=n){
                count++;
                ind=up;
            }
            else break;
        }
        return count;
    }
};