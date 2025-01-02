class Solution {
public:
    bool isCharVowel(char c){
        return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
    }
    bool isvowel(char c1,char c2){
        return isCharVowel(c1) and isCharVowel(c2);        
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pref(n,0);
        for(int i=0;i<n;i++){
            string s=words[i];
            if(isvowel(s[s.size()-1],s[0])){
                pref[i]=1;
            }
        }
        for(int i=1;i<n;i++){pref[i]+=pref[i-1];}
        vector<int>res;
        for(auto a:queries){
            if(a[0]==0){
                res.push_back(pref[a[1]]);            
            }
            else{
                res.push_back(pref[a[1]]-pref[a[0]-1]);
            }
        }
        return res;
    }
};