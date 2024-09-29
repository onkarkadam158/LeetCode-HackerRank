class Solution {
public:
    unordered_map<char,int>mp;
    bool containVowels(string &s){
        unordered_map<char,int>mp;
        mp['a']=0,mp['e']=0,mp['i']=0,mp['o']=0,mp['u']=0;
        for(auto a:s){
            if(mp.find(a)!=mp.end()){
                mp[a]++;
            }
        }
        for(auto a:mp){
            if(a.second==0) return false;
        }
        return true;
    }
    bool kConsonants(string& s,int k){
        int cnt=0;
        for(auto a:s){
            if(mp.find(a)==mp.end()){
                cnt++;
            }
        }
        return cnt==k;
    }
    bool check(string& s,int k){
        int n=s.size();
        if(n<(k+5)) return false;
        return containVowels(s) and kConsonants(s,k);
    }
    int countOfSubstrings(string word, int k) {
        int result=0;
        mp['a']=0,mp['e']=0,mp['i']=0,mp['o']=0,mp['u']=0;
        int n=word.size();
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=word[j];
                if(check(temp,k)){
                    result++;
                }
            }
        }
        return result;
    }
};