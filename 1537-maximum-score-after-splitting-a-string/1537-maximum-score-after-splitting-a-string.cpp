class Solution {
public:
    int maxScore(string s) {
        vector<int>pref,suf;
        int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') cnt1++;
            pref.push_back(cnt1);
        }
        for(int i=s.size()-1;i>=0; i--){
            if(s[i]=='1') cnt2++;
            suf.push_back(cnt2);
        }
        reverse(suf.begin(),suf.end());
        int res=0;
        for(int i=0;i<s.size()-1;i++){
            res=max(res,pref[i]+suf[i+1]);
        }
        return res;
    }
};