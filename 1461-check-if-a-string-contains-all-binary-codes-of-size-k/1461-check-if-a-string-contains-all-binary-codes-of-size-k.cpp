class Solution {
public:
    string getBinString(int n,int k){
        string res="";
        while(n){
            res+=('0'+n%2);
            n=n/2;
        }
        while(res.size()<k) res+='0';
        reverse(res.begin(),res.end());
        return res;
    }
    bool bruteforce(string& s,int k){
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i++){
            string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                mp[temp]++;
            }
        }
        for(int i=0;i<pow(2,k);i++){
            string str=getBinString(i,k);
            cout<<str<<"\n";
            if(mp.find(str)==mp.end()) return false;
        }
        return true;
    }
    bool hasAllCodes(string s, int k) {
        // return bruteforce(s,k); // O(n^2 + pow(2,k)) time and space
        if(k>=s.size()) return false;
        unordered_map<string,int>mp;
        for(int i=0;i<s.size()-k+1;i++){
            string temp="";
            for(int j=i;j<i+k;j++){
                temp+=s[j];
            }
            mp[temp]++;
        }
        return mp.size()==(pow(2,k));
    }
};