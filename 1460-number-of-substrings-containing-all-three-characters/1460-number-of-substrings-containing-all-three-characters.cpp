class Solution {
public:
    bool allgtone(unordered_map<char,int>&mp){
        if(mp['a']>0 and mp['b']>0 and mp['c']>0) return true;
        return false;
    }
    int numberOfSubstrings(string s) {
        long long int n=s.size();
        long long int all=(n*(n+1))/2,count=0;
        unordered_map<char,int>mp;
        mp['a']=0,mp['b']=0,mp['c']=0;
        for(int i=0,j=0;i<n,j<n;j++){
            mp[s[j]]++;
            if(!allgtone(mp)){
                count+=j-i+1;
            }
            else{
                while(i<j and allgtone(mp)){
                    mp[s[i]]--;
                    i++;
                }
                count+=j-i+1;
            }
        }
        return all-count;
    }
};