class Solution {
public:
    int binaryGap(int n) {
        int res=0,prev=-1;
        int i=0;
        while(n){
            if(n%2){
                if(prev!=-1){
                    res=max(res,i-prev);
                }
                prev=i;
            }
            i++;
            n=n/2;
        }

        return res;
    }
};