class Solution {
public:
    vector<int> bruteforce(vector<int>& nums){
        vector<int> res;
        unordered_map<int,int>mp;
        for(auto a:nums)mp[a]++;
        for(auto a:mp){
            if(a.second==1)res.push_back(a.first);
        }
        return res;
    }
    vector<int> bitManipulationBucketsSolution(vector<int>& nums){
        int b1=0,b2=0;
        long allXOR=0;
        for(auto a:nums)allXOR^=a;
        int rightMostBit=(allXOR^(allXOR-1)) & allXOR;
        for(auto a:nums){
            if(rightMostBit&a){
                b1=b1^a;
            }
            else{
                b2=b2^a;
            }
        }
        return {b1,b2};
    }
    vector<int> singleNumber(vector<int>& nums) {
        // return bruteforce(nums);//time O(n) space O(n)

        return bitManipulationBucketsSolution(nums);//time O(n) space O(1)
    }
};