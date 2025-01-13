class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(k>n) return false;
        if(k==n) return true;
        vector<int>mp(26,0);
        for(auto ch:s){
            mp[ch-'a']++;
        }
        int palSize=n-k+1;
        int count=0,oddtaken=false;
        for(auto a:mp){
            if(a%2==0){
                count+=a;
            }
            else{
                if(!oddtaken){
                    count+=a;
                    oddtaken=true;
                }
                else{
                    count+=a-1;
                }
            }
        }

        return count>=palSize;
    }
};