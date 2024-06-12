class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++)
            res=res^nums[i];
        return res;
        /*for(int i=0;i<n;i++)
        {
            int temp=nums[i];
            temp= (temp>0)?temp:-1*temp;
            nums[temp-1]*=(-1);
        }
        int i;
        for( i=0;i<n;i++)
        {
            if(nums[i]<0)
                break;
        }
        return i+1;
        sort(nums.begin(),nums.end());
        int res;
        for(int i=1;i<n;i++)
            if(nums[i-1]==nums[i])
            {
                nums[i-1]=0;
                nums[i]=0;
            }
        for(int i=0;i<n;i++)
            if(nums[i]!=0)
                res=nums[i];
        return res; */       
    }
};