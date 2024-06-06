class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        map<int,int>mp;
        for(auto a:nums)mp[a]++;
        while(mp.size()>0){
            int t=k-1;
            int num=mp.begin()->first;
            mp[num]--;
            if(mp[num]==0)mp.erase(num);
            while(t--){
                num++;
                if(mp.find(num)==mp.end()) return false;
                mp[num]--;
                if(mp[num]==0)mp.erase(num);
            }
        }
        return true;
    }
};