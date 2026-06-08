class Solution {
public:
    vector<int>bruteforce(vector<int>& nums, int pivot){
        int n=nums.size();
        vector<int>res;
        for(auto a:nums) {
            if(a<pivot) res.push_back(a);
        }
        for(auto a:nums) {
            if(a==pivot) res.push_back(a);
        }
        for(auto a:nums) {
            if(a>pivot) res.push_back(a);
        }
        return res;
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        return bruteforce(nums,pivot);
        
    }
};