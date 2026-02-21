class Solution {
public:
    int countNumOfBits(int num){
        int count=0;
        while(num){
            count+=num%2;
            num/=2;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>primes={2,3,5,7,11,13,17,19,23,29,31};
        int count=0;
        for(int num=left;num<=right;num++){
            int cnt=countNumOfBits(num);
            if(primes.find(cnt)!=primes.end()){
                count++;
            }
        }
        return count;
    }
};