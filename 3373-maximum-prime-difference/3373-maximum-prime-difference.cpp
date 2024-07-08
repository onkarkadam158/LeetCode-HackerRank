class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!isprime(nums[i])){
                nums[i]=-1;
            }
        }
        int mini=-1,maxi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=-1){
                if(mini==-1){
                    mini=i,maxi=i;
                }
                else{
                    maxi=i;
                }
            }
        }
        return maxi-mini;
    }
};