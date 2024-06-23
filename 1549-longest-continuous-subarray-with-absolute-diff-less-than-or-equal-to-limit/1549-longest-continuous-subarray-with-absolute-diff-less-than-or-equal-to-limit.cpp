class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int>mp;
        int n=nums.size(),res=0;
        for(int j=0,i=0;j<n;j++){
            mp[nums[j]]++;
            auto end=mp.end();end--;
            int maxi=end->first;
            int mini=mp.begin()->first;
            if(abs(maxi-mini)<=limit){
                res=max(res,j-i+1);
                cout<<j<<" "<<i<<endl;
            }
            else{
                while(i<j and abs(maxi-mini)>limit){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    mini=mp.begin()->first;
                    end=mp.end();end--;
                    maxi=end->first;
                    i++;
                }
                if(abs(maxi-mini)<=limit){
                    res=max(res,j-i+1);
                    cout<<j<<" "<<i<<endl;
                }
            }
        }
        return res;
    }
};