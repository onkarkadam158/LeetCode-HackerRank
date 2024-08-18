class Solution {
public:

    bool isUgly(int n) {
        while(n>1){
            if(n%5==0)
                n/=5;
            else if(n%3==0)
                n/=3;
            else if(n%2==0)
                n/=2;
            else
                break;
        }
        return n==1;
    }
    int bruteforce(int n){
        int num=1,count=0;
        while(count<n){
            if(isUgly(num)){
                count++;
            }
            num++;
        }
        return num-1;
    }
    int nthUglyNumber(int n) {
        // return bruteforce(n);

        vector<int>dp(n);
        dp[0]=1;
        int p1=0,p2=0,p3=0;
        for(int i=1;i<n;i++){
            int twoMul =dp[p1]*2;
            int threeMul = dp[p2]*3;
            int fiveMul = dp[p3]*5;
            dp[i]=min(twoMul,min(threeMul,fiveMul));
            if(dp[i]==twoMul)p1++;
            if(dp[i]==threeMul)p2++;
            if(dp[i]==fiveMul)p3++;
        }

        return dp[n-1];
    }
};