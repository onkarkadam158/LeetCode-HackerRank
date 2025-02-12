class Solution {
public:
    int digsum(int n)
    {
        int sum=0;
        while(n){sum+=n%10;n=n/10;}
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(auto num:nums){
            mp[digsum(num)].push_back(num);
        }
        int res=-1;
        for(auto a:mp){
            int n=a.second.size();
            if(n>1){
                sort(a.second.begin(),a.second.end());
                res=max(res,a.second[n-1]+a.second[n-2]);
            }
        }
        return res;
    }
};