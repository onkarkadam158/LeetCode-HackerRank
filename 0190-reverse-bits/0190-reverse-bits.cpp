class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long res=0;
        int i=0;
        while(n){
            if(n%2)
                res+=1<<(31-i);
            i++;
            n=n>>1;
        }
        return res;
    }
};