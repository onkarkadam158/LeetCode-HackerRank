class Solution {
public:
    int maxOperations(string s) {
        int sum=0,chunks=0,flag=0,n=s.size();
        //basically count the no. of chunks of zeroes to the right of '1' that much time you can move 1 
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                flag=0;
                sum+=chunks;
            }
            else{
                if(flag==0)chunks++;
                flag=1;
            }            
        }
        return sum;
    }
};