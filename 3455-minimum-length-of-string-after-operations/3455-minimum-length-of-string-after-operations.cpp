class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto a:s){
            mp[a]++;
        }
        int count=0;
        for(auto a:mp){
            if(a.second<=2){
                count+=a.second;
            }
            else{
                if(a.second%2) count++;
                else count+=2;
            }
        }
        return count;
    }
};