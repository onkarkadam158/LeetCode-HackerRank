class Solution {
public:
    int bruteforce(vector<int>& nums) {
        int n=nums.size();
        int maxAnd=0,result=1;
        for(int i=0;i<n;i++){
            int temp=nums[i];
            for( int j=i ;j<n;j++){
                temp=temp&nums[j];
                maxAnd=max(maxAnd,temp);
            }
        }
        for(int i=0;i<n;i++){
            int temp=nums[i];
            for(int j=i+1;j<n;j++){
                temp=temp&nums[j];
                if(temp==maxAnd){
                    result=max(result,j-i+1);
                }
            }
        }
        return result;
    }
    int longestSubarray(vector<int>& nums) {
        // return bruteforce(nums);
        int n=nums.size();
        int maxEle=*max_element(nums.begin(),nums.end());
        int res=1;
        for(int i=0;i<n;){
            if(nums[i]==maxEle){
                int count=0;
                while(i<n and nums[i]==maxEle){
                    i++;
                    count++;
                }
                res=max(res,count);
            }
            else{
                i++;
            }
        }

        return res;
    }
};