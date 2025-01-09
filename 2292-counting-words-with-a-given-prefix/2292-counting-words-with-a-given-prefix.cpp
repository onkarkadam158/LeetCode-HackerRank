class Solution {
public:
    bool prefix(string s1,string s2){
        if(s1.size()<s2.size())
            return false;
        
        for(int i=0;i<s2.size();i++){
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto &word:words){
            if(prefix(word,pref)){
                count++;
            }
        }
        return count;
    }
};