class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int res=INT_MAX;
        for(auto a:mp){
            int size=a.second.size();
            if(size>2){
                for(int ind=2;ind<size;ind++){
                    int i=a.second[ind-2];
                    int k=a.second[ind];
                    res=min(res,2*(k-i));
                }
            }
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};