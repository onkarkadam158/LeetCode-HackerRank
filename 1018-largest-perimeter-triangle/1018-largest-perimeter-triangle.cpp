class Solution {
public:
    bool isTriangle(int a,int b,int c){
        if(((a+b)<=c) or ((a+c)<=b) or ((b+c)<=a)) return false;
        return true;
    }
    int bruteforce(vector<int>&nums){
        int n=nums.size();
        int perimeter=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(isTriangle(nums[i],nums[j],nums[k])){
                        perimeter=max(nums[i]+nums[j]+nums[k],perimeter);
                    }
                }
            }
        }
        return perimeter;
    }
    int optimal(vector<int>&nums){
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i-2]+nums[i-1]>nums[i]){
                return nums[i-2]+nums[i-1]+nums[i];
            }
            }
        return 0;

    }
    int largestPerimeter(vector<int>& nums) {
        // return bruteforce(nums);
        
        return optimal(nums);
    }
};