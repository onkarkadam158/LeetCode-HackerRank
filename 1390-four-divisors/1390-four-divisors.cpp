class Solution {
public:
    int getSum(int num){
        int count=0,sum=0;
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                count++;
                sum+=i;
                if(i!=(num/i)){
                    count++;
                    sum+=(num/i);
                }
                else return 0;
            }
            if(count>4) return 0;
        }
        if(count!=4) return 0;
        return sum;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(auto &num:nums){
            sum+=getSum(num);
        }
        return sum;
    }
};