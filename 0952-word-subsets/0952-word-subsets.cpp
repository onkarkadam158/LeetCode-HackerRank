class Solution {
public:
    bool isBsubsetOfA(string &b,string& a){
        vector<int>mp1(26,0),mp2(26,0);
        
        for(auto ch:a) mp1[ch-'a']++;
        for(auto ch:b) mp2[ch-'a']++;
        
        for(int i=0;i<26;i++){
            if(mp1[i] < mp2[i]) return false;
        }
        return true;
    }
    bool isUniversal(string& a,vector<string>&words2){
        for(auto b:words2){
            if(!isBsubsetOfA(b,a)){
                return false;
            }
        }
        return true;
    }
    vector<string> bruteforce(vector<string>& words1, vector<string>& words2){
        vector<string>res;
        for(auto word:words1){
            if(isUniversal(word,words2)){
                res.push_back(word);
            }
        }
        return res;
    }
    bool issubset(vector<int>&temp,vector<int>&mp){
        for(int i=0;i<26;i++){
            if(temp[i]< mp[i]) return false;
        }
        return true;
    }
    vector<string> optimal(vector<string>& words1, vector<string>& words2){
        vector<int>mp(26,0);
        for(auto word:words2){
            vector<int>temp(26,0);
            for(auto ch:word){
                temp[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                mp[i]=max(mp[i],temp[i]);
            }
        }
        vector<string>res;
        for(auto word:words1){
            vector<int>temp(26,0);
            for(auto ch:word){
                temp[ch-'a']++;
            }
            if(issubset(temp,mp)){
                res.push_back(word);
            }
        }
        return res;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // return bruteforce(words1,words2); //TLE
        return optimal(words1,words2);
    }
};