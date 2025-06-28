class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>arr1,arr2;
        for(int i=0;i<nums.size();i++){
            arr1.push_back({nums[i],i});
        }
        sort(arr1.rbegin(),arr1.rend());
        vector<int>res;
        for(int i=0;i<k;i++){
            arr2.push_back({arr1[i].second,arr1[i].first});
        }
        sort(arr2.begin(),arr2.end());
        for(auto a:arr2){
            res.push_back(a.second);
        }
        return res;
    }
};