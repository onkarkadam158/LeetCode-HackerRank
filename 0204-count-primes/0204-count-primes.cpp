class Solution {
public:
    bool isprime(int n){
        if(n==1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }

    int bruteforce(int n){
        int count=0;
        for(int i=2;i<n;i++){
            if(isprime(i)) count++;
        }
        return count;
    }
    void findprimes(vector<int>&arr,int n){
        for(int i=2;i<=n;i++){
            if(arr[i]){
                for(int j=2;i*j<=n;j++){
                    arr[i*j]=0;
                }
            }
        }
    }
    int optimal(int n){
        vector<int>arr(n+1,1);
        findprimes(arr,n);
        int count=0;
        for(int i=2;i<n;i++){
            // if(isprime(i)) count++;
            if(arr[i])count++;
        }
        return count;
    }
    int countPrimes(int n) {
        // return bruteforce(n);//o(n*sqrt(n))

        return optimal(n);//o(n) sieve of erotosthenes logic 
    }
};