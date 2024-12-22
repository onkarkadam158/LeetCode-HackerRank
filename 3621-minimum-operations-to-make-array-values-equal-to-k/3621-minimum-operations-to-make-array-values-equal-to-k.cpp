class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto a:nums){
            if(a<k) return -1;
            mp[a]++;
        }
        if(mp.find(k)==mp.end()) return mp.size();
        return mp.size()-1;
    }
};