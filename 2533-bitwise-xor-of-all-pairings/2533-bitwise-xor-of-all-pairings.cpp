class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int res=0;
        
        if(m%2){
            for(auto a:nums1){
                res=res^a;
            }
        }
        if(n%2){
            for(auto a:nums2){
                res=res^a;
            }
        }
        return res;
    }
};