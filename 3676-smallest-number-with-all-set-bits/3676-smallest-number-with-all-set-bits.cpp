class Solution {
public:
    int smallestNumber(int n) {
        int cnt=0;
        while(n){
            cnt++;
            n=n/2;
        }
        return (1<<cnt)-1;
    }
};