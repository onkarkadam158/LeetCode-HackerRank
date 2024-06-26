class Solution {
public:
    double get(double x,long long n){
        if(n==0) return 1;
        if(n%2){
            return x*get(x,n-1);
        }
        return get(x,n/2)*get(x,n/2);
    }
    double bruteforce(double x,long long n){
        if(n<0){
            n=-n;
            x=1/x;
        }
        double ans=1;
        while(n>0){
            if(n%2==0){
                x=x*x;
                n=n/2;
            }
            else{
                ans=ans*x;
                n--;
            }
        }
        return ans;
    }
    double myPow(double x, int n) {
        // return pow(x,n); // libary function

        return bruteforce( x, n); //gives TLE time O(LogN) 
    }
};