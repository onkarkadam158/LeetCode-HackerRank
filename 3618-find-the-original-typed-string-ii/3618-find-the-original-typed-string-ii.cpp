class Solution {
public:
    long long mod = 1e9+7;
    long long M = 1e9+7;
    vector<int>getFrequency(string& word,int n){
        vector<int>res;
        char prev='Z';
        int count=0;
        for(auto &ch:word){
            if(prev!='Z' and ch!=prev){
                res.push_back(count);
                count=0;
            }
            count++;
            prev=ch;
        }
        if(count) res.push_back(count);
        return res;
    }
    int solve(int ind,int m,vector<int>&freq,int target){
        if(ind>=m){
            if(target<=0) return 1;
            return 0;
        }
        int res=0;
        for(int count=1;count<=freq[ind];count++){
            res+=solve(ind+1,m,freq,target-count)%mod;
        }

        return res%mod;
    }

    long long memoization(int ind,int m,vector<int>&freq,int target,vector<vector<long long>>&dp,int n){
        if(ind>=m){
            if(target<=0) return 1;
            return 0;
        }
        if (target < 0) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        long long res=0;
        for(int count=1;count<=freq[ind];count++){
            res+=memoization(ind+1,m,freq,target-count,dp,n)%mod;
        }

        return dp[ind][target]=res%mod;
    }
    int possibleStringCount(string word, int k) {
        // int n=word.size();
        
        // vector<int>freq=getFrequency(word,n);
        // for(auto a:freq) cout<<a<<" ";

        // int m=freq.size();
        
        // Bruteforce solution
        // return solve(0,m,freq,k)%mod;
    
        // Memoization solution
        // vector<vector<long long>>dp(m+1,vector<long long>(k+1,-1));
        // return memoization(0,m,freq,k,dp,n)%mod;
        
 if(k > word.length())
            return 0;
        
        vector<int> freq;
        int count = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) {
                count++;
            } else {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1; //total possible strings
        for(int &f : freq) {
            P = (P * f) % M;
        }
        
        if(freq.size() >= k) {
            return P;
        }
        int n = freq.size();
        
        vector<vector<int>> t(n+1, vector<int>(k+1, 0));

        for(int count = k-1; count >= 0; count--) {
            t[n][count] = 1;
        }

        for(int i = n-1; i >= 0; i--) {

            vector<int> prefix(k+1, 0);
            for(int h = 1; h <= k; h++) {
                prefix[h] = (prefix[h-1] + t[i+1][h-1]) % M;
            }

            for(int count = k-1; count >= 0; count--) {
                
                int l = count + 1;
                int r = count + freq[i];

                if(r+1 > k) {
                    r = k-1;
                }

                if(l <= r) {
                    t[i][count] = (prefix[r+1] - prefix[l] + M) % M;
                }
                
            }
        }

        long long invalidCount = t[0][0];

        return (P - invalidCount + M) % M;

    
    }
};