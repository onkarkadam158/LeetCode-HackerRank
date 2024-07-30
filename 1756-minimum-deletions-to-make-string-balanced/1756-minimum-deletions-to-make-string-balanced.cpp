class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>pref(n,0),suff(n,0);
        int cntb=0,cnta=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b')cntb++;
            pref[i]=cntb;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a') cnta++;
            suff[i]=cnta;
        }
        int count=n;
        for(int i=0;i<n;i++){
            count=min(count,pref[i]+suff[i]);
        }
        return count-1;
    }
};