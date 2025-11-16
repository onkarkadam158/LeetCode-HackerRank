class Solution {
public:
    int mod=1e9+7;
    int numSub(string s) {
        long long count=0,result=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count+=1;
            }
            else{
                result=(result+((count*(count+1)))/2)%mod;
                count=0;
            }
        }
        result=(result+((count*(count+1)))/2)%mod;
        
        return result%mod;
    }
};