class Solution {
public:
    int solution1(vector<int>&nums){ ///GAVE TLE
        int n=nums.size();
        int moves=0,maxi=n,mini=n;
        map<int,int>mp,mp1;
        for(auto a:nums){
            mp[a]++;
            maxi=max(maxi,a);
            mini=min(mini,a);
        }
        for(int i=mini;i<=100000;i++){
            if(mp.find(i)==mp.end()) mp1[i]=1;
        }
        auto itr=mp1.begin();
        for(auto a:mp){
            int num=a.first,freq=a.second;
            cout<<num<<" "<<freq<<" \n";
            while(freq>1){
                if(num<itr->first)moves+=abs(num - int(itr->first)),freq--;
                itr++;
            }
        }
        return moves;
    }
    int minIncrementForUnique(vector<int>& nums) {
        // return solution1(num);
        int moves=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                moves+=abs(nums[i-1]+1-nums[i]);
                nums[i]=nums[i-1]+1;
            }
        }
        return moves;
    }
};