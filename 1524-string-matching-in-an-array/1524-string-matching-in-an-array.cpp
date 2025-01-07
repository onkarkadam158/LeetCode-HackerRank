class Solution {
public:
    bool issubstring(string s,string s1){
        if(s.size()>s1.size()) return false;
        for(int i=0;i<s1.size();i++){
            string temp="";
            for(int j=i;j<s1.size();j++){
                temp+=s1[j];
                if(s==temp) return true;
            }
        }
        return false;
    }
    bool isubstr(string s,int ind,vector<string>& words){
        for(int i=0;i<words.size();i++){
            if(i!=ind and issubstring(s,words[i])){
                return true;
            }
        }
        return false;
    }
    vector<string> bruteforce(vector<string>& words){
        vector<string>res;
        for(int i=0;i<words.size();i++){
            if(isubstr(words[i],i,words)){
                res.push_back(words[i]);
            }
        }

        return res;
    }
    void fillinSubstrings(string s,unordered_map<string,int>&mp){
        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                mp[temp]++;
            }
        }
    }
    vector<string> stringMatching(vector<string>& words) {
        // return bruteforce(words);
        unordered_map<string,int>mp;
        for(auto a:words){
            fillinSubstrings(a,mp);
        }
        vector<string>res;
        for(auto a:words){
            if(mp.find(a)!=mp.end()){
                if(mp[a]>1) res.push_back(a);
            }
        }
        return res;
    }
};













