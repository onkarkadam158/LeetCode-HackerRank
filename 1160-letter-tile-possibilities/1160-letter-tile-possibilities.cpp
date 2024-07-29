class Solution {
public:
    int solve(int ind,int n,unordered_map<char,int>&mp){
        if(ind>=n) return 0;
        int count=0;
        for(auto &a:mp){
            if(a.second>0){
                a.second--;
                count+=solve(ind+1,n,mp)+1;
                a.second++;
            }
        }
        return count;
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int>mp;
        int n=tiles.size();
        for(auto a:tiles){
            mp[a]++;
        }
        return solve(0,n,mp);
    }
};