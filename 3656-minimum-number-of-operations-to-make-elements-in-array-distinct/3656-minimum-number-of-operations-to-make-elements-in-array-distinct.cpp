class Solution {
public:
    int solution1(vector<int>&nums){
        int n=nums.size();
        unordered_map<int,int>mp;
        int i;
        for( i=n-1;i>=0;i--){
            if(mp.find(nums[i])!=mp.end()){
                break;
            }
            mp[nums[i]]++;
        }
        if((i+1)%3==0) return (i+1)/3;
        return ((i+1)/3)+1;
    }
    int minimumOperations(vector<int>& nums) {
        return solution1(nums);
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