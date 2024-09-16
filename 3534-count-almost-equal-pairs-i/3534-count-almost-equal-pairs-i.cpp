class Solution {
public:
    int toInt(vector<int>nums){
        int num=0;
        for(int i=0;i<nums.size();i++){
            num=num+nums[i]*pow(10,i);
        }
        return num;
    }
    
    bool canEqual(int a,int b){
        if(a==b) return true;
        vector<int>mp1(7,0);
        int i=0;
        while(a){
            mp1[i++]=a%10;
            a=a/10;
        }
        // for(auto a:mp1)cout<<a<<" ";
        // cout<<"\n";
        for(int i=0;i<7;i++){
            for(int j=i+1;j<7;j++){
                swap(mp1[i],mp1[j]);
                if(toInt(mp1)==b) return true;
                swap(mp1[i],mp1[j]);
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        cout<<toInt({2,1,0,0,0,0,});
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // cout<<nums[i]<<" "<<nums[j]<<"\n";
                if(canEqual(nums[i],nums[j])){
                    count++;
                }
            }
        }

        return count;
    }
};