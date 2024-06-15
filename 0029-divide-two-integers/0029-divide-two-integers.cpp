class Solution {
public:
    int solution(int dividend, int divisor){
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        return dividend/divisor;
    }
    int getSign(int a,int b){
        if((a<0 and b>=0 ) or (a>=0 and b<0)) return -1;
        return 1;
    }
    long long bitSolution(long long dividend, long long divisor){
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int sign=getSign(dividend,divisor);
        long long n=abs(dividend),d=abs(divisor);
        long long answer=0;
        while(n>=d){
            long long cnt=0;
            while(n>=(d<<cnt)){
                cnt++;
            }
            n=n-(d<<(cnt-1));
            answer+=(1<<(cnt-1));
        }
        return sign*answer;
    }
    int divide(int dividend, int divisor) {
        // return solution(dividend, divisor);
        return bitSolution(dividend, divisor);
    }
};