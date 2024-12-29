class Solution {
public:
    int n,m,mod=1e9+7;
    int solve(int j,vector<string>&words,string& target,int k,vector<unordered_map<char,int>>&freq,vector<vector<int>>&dp){
        if(k>=(target.size())) return 1;
        if(j>=(words[0].size())) return 0;

        if(dp[j][k]!=-1) return dp[j][k];

        long take=0,ntake=0;
        if(freq[j].find(target[k])!=freq[j].end()){
            long count=freq[j][target[k]];
            take=(count*solve(j+1,words,target,k+1,freq,dp))%mod;
        }
        ntake=solve(j+1,words,target,k,freq,dp)%mod;
                
        return  dp[j][k]=(take+ntake)%mod;
    }
    int numWays(vector<string>& words, string target) {
        n=words.size(),m=words[0].size();
        vector<unordered_map<char,int>>freq;
        for(int i=0;i<m;i++){
            unordered_map<char,int>mp;
            for(int j=0;j<n;j++){
                char ch=words[j][i];
                mp[ch]++;
            }
            freq.push_back(mp);
        }
        int k=target.size();
        vector<vector<int>>dp(m+1,vector<int>(k+1,-1));
        return solve(0,words,target,0,freq,dp);
    }
};