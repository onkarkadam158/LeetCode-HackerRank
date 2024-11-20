class Solution {
public:
    bool check(unordered_map<char,int>&mp1,unordered_map<char,int>&mp2){
        for(auto a:mp2){
            if(mp1[a.first] < a.second) return false;
        }
        return true;
    }
    int takeCharacters(string s, int k) {
        unordered_map<char,int>mp1,mp2;
        mp1['a']=0,mp1['b']=0,mp1['c']=0;
        mp2=mp1;
        for(auto a:s){ mp1[a]++;}
        for(auto& a:mp1){
            if(a.second<k) return -1;
            else
                a.second-=k;
        }
        int n=s.size(),res=-1;
        for(int i=0,j=0;i<n,j<n;j++){
            mp2[s[j]]++;
            if(check(mp1,mp2)){
                res=max(res,j-i+1);
            }
            else{
                while(!check(mp1,mp2) and i<=j){
                    mp2[s[i]]--;
                    i++;
                }
                if(check(mp1,mp2)){
                    res=max(res,j-i+1);
                }
            }
        }
        if(res==-1) return -1;
        return n-res;
    }
};