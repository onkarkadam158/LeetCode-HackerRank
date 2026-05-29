class Solution {
public:
    int sumDigit(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto& num:nums){
            mini=min(mini,sumDigit(num));
        }

        return mini;
    }
};