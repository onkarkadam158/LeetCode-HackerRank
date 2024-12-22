class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto a:nums) mp[a]++;
        int count=0;
        if(mp.size()==n) return 0;
        for(int i=0;i<n;i+=3){
            int j=i;
            while(j<min(i+3,n)){
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
            }
            count++;
            if(mp.size()==(n-j)) return count;
        }
        return count;
    }
};