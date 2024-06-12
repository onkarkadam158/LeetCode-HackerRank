class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algorithm one pass time O(n) space o(1)
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++,mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        //two pass solution time o(2n) space o(1)
        /*int zero=0,one=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zero++;
            else if(nums[i]==1)
                one++;
            else
                two++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i<zero)
                nums[i]=0;
            else if(zero<=i && i<(one+zero))
                nums[i]=1;
            else
                nums[i]=2;
        }*/
    }
};