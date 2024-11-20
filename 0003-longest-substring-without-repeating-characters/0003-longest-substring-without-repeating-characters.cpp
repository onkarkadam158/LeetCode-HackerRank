class Solution {
public:
    int bruteforce(string& s){
        int ans=0;
        for(int i=0;i<s.size();i++){
            int count=0;
            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++)
            {
                if(mp.find(s[j])==mp.end())
                    count++,mp[s[j]]++;
                else
                    break;
            }
            ans=max(count,ans);
        }
        return ans;
    }
    int optimal(string& s){
        int n=s.size();
        int res=0;
        unordered_map<char,int>mp;
        for(int i=0,j=0;j<n;j++){
            mp[s[j]]++;
            if(mp.size()==(j-i+1)){
                res=max(res,(j-i+1));
            }
            else{
                while(i<j and mp.size()!=(j-i+1)){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                if(mp.size()==(j-i+1)){
                    res=max(res,(j-i+1));
                }
            }
        }
        return res;
    }
    int lengthOfLongestSubstring(string s) {
        // return bruteforce(s);
        return optimal(s);
    }
};