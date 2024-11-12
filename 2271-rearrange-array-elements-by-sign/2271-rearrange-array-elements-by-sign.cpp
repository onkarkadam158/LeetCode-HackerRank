class Solution {
public:
    vector<int>bruteforce(vector<int>& nums){
        vector<int>neg,pos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        int k=0,i=0,j=0;
        while(k<nums.size()){
            if(k%2==0)
                nums[k++]=pos[i++];
            else
                nums[k++]=neg[j++];
        }
        return nums;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        // return bruteforce(nums);
        int pos=0,neg=1;
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                res[neg]=nums[i];
                neg+=2;
            }
            else{
                res[pos]=nums[i];
                pos+=2;
            }
        }
        return res;
    }
};