class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        vector<int>pref(n,0),suff(n,0);
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            pref[i]=mp.size();
        }
        mp.clear();
        for(int i=0;i<n;i++){
            mp[s[n-1-i]]++;
            suff[n-1-i]=mp.size();
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            count+=(pref[i]==suff[i+1]);
        }
        return count;
    }
};