class Solution {
public:
    vector<int> getLis(int n,vector<int>&nums){
        vector<int>res(n,1);
        for(int i=1;i<n;i++){
            int maxi=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    maxi=max(maxi,res[j]+1);
                }
            }
            res[i]=maxi;
        }
        return res;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
               
        vector<int>lis1=getLis(n,nums);
        reverse(nums.begin(),nums.end());
        for(auto a:lis1)cout<<a<<" ";

        vector<int>lis2=getLis(n,nums);
        reverse(lis2.begin(),lis2.end());

        cout<<endl;
        for(auto a:lis2)cout<<a<<" ";
        int ans=0;
        for(int i=0;i<n;i++){
            if(lis1[i]>1 and lis2[i]>1)
                ans=max(ans,lis1[i]+lis2[i] -1);
        }
        return n-ans;
    }
};