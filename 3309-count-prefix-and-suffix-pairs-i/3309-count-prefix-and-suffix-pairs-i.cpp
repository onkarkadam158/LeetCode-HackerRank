class Solution {
public:
    bool isPrefixAndSuffix(string s1, string s2){
        int n=s1.size(),m=s2.size();
        if(n>m) return false;
        for(int i=0;i<min(n,m);i++){
            if(s1[i]!=s2[i]) return false;
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        for(int i=0;i<min(n,m);i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0,n=words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                count+=isPrefixAndSuffix(words[i], words[j]);
            }
        }
        
        return count;
    }
};