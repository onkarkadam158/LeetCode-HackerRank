class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(auto a:s){
            mp[a]++;
        }
        int res=-1000;
        // for(auto a:mp) cout<<a.first<<" "<<a.second<<" ";
        for(auto a:mp){
            for(auto b:mp){
                if(a.first!=b.first){
                    if( (a.second%2)==1  and (b.second)%2==0) {
                        res=max(res,(a.second-b.second));
                    }
                }
            }
            
        }

        return res;
    }
};