class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++){nums[i]=nums[i]%2;}
        unordered_map<long long ,int>mp;
        long long sum=0;
        mp[0]=1;
        for(auto a:nums){
            sum+=a;
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};