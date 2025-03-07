class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n=1e6+1;
        vector<int>primes(n,1);
        primes[1]=0;
        primes[0]=0;
        for(int i=2;i*i<n;i++){
            if(primes[i]){
                for(int j=i+i;j<n;j+=i){
                    primes[j]=0;
                }
            }
        }
        int num1=-1,num2=-1;
        int mini=right-left+1;
        vector<int>ans={-1,-1};
        for(int i=left;i<=right;i++){
            if(primes[i]){
                if(num1==-1 and num2==-1){
                    num1=i;
                }
                else {
                    num2=num1;
                    num1=i;
                }
                if((num1-num2) < mini){
                    mini=(num1-num2);
                    ans={num2,num1};
                }
            }
        }
        
        return ans;
    }
};