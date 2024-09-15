class Solution {
public:
    vector<char>vowels={'a','e','i','o','u'};
    bool isvowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
    bool check(unordered_map<char,int>&mp){
        for(auto a:vowels){
            if(mp.find(a)!=mp.end()) {
                if(mp[a]%2) return false;
            }
        }
        return true;
    }
    int findTheLongestSubstring(string s) {
        int n=s.size(),res=0;
        int mask=0;
        vector<int>pref;
        pref.push_back(0);
        for(int i=0;i<n;i++){
            if(isvowel(s[i])){
                mask=mask^(1<<(s[i]-'a'));
            }
            pref.push_back(mask);
            cout<<mask<<" ";
        }
        unordered_map<int,int>mp;
        // mp[0]=-1;
        for(int i=0;i<pref.size();i++){
            if(mp.find(pref[i])!=mp.end()){
                res=max(res,i-mp[pref[i]]);
            }
            else{
                mp[pref[i]]=i;
            }
        }
        return res;
    }
};