class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n) return time+1;
        int i=1,flag=0;
        while(time--){
            if(flag==0 ){
                if(i<n)
                    i++;
                if(i==n)
                    flag=1;
            }
            else{
                if(i>1)
                    i--;
                if(i==1)
                    flag=0;
            }
        }
        return i;
    }
};