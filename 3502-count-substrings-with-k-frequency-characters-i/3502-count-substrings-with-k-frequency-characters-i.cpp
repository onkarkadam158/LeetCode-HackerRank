class Solution {
public:
    bool check(unordered_map<int,int>&mp,int k){
        for(auto a:mp){
            if(a.second>=k) return true;
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(check(mp,k)){
                    count++;
                }
            }
        }
        return count;
    }
};