class Solution {
public:
    int sortingSolution(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=1;i<n-1;i++){
            if(nums[i]!=nums[i-1] and nums[i]!=nums[i+1]) return nums[i];
        }
        if(nums[0]!=nums[1]) return nums[0];
        return nums[n-1];
    }
    int mapSolution(vector<int>& nums){
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto a:nums)mp[a]++;
        for(auto a:mp){
            if(a.second==1) return a.first;
        }
        return -1;
    }
    int bitManipulationSolution(vector<int>& nums){
        int result=0;
        int n=nums.size();
        for(int i=0;i<32;i++){  
            int cnt=0;
            for(auto a:nums){
                int num=a;
                if((num>>i)&1)cnt++;
            }
            if(cnt%3)result+=(1<<i);
        }
        return result;
    }
    
    int bucketsSolution(vector<int>&nums){
        int n=nums.size();
        //basically ones in ones bucket when first occurred, when 2nd occurred delete from ones bucket and add to twos bucket and so on
        // nums[i] will got to ones if not in twos 
        //nums[i] will go to twos if it is in ones
        int ones=0,twos=0;
        for(int i=0;i<n;i++){
            ones=(ones^nums[i])&(~twos);
            twos=(twos^nums[i])&(~ones);
        }
        return ones;
    }
    int singleNumber(vector<int>& nums) {

        // return sortingSolution(nums); time O(nlogn) space O(1)

        // return mapSolution(nums); //time O(n) space O(n)

        // return bitManipulationSolution(nums);//time O(32*n) space O(1)

        return bucketsSolution(nums);//time O(n) space O(1)
    }
};