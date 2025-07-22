class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res=0,n=nums.size(),sum=0;
        unordered_map<int,int>mp;
        for(int i=0,j=0;i<n,j<n;j++){
            mp[nums[j]]++;
            sum+=nums[j];
            if(mp.size()==(j-i+1)){
                res=max(res,sum);
            }
            else if(mp.size()<(j-i+1)){
                while(i<j and mp.size()<(j-i+1)){
                    mp[nums[i]]--;
                    sum-=nums[i];
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    i++;
                }
                if(mp.size()==(j-i+1)){
                    res=max(res,sum);
                }
            }
        }


        return res;
    }
};