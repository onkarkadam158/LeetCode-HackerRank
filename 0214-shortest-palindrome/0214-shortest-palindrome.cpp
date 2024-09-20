class Solution {
public:
    //bruteforce
    bool ispal(string &s,int ind){
        int n=s.size();
        int i=ind,j=n-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
    string bruteforce(string& s){
        reverse(s.begin(),s.end());
        int n=s.size(),i;
        for(i=0;i<n;i++){
            if(!ispal(s,i)){
                ;
            }
            else break;
        }
        string res=s.substr(0,i);
        reverse(s.begin(),s.end());
        return res+s;
    }
    //KMP Algo optimal
    void computeLPS(string& pat,vector<int>&lps){
        int m=pat.size();
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i++]=len;
            }
            else{
                if(len!=0) len=lps[len-1];
                else{
                    lps[i++]=0;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        // return bruteforce(s);

        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+"-"+rev;
        vector<int>lps(2*n+1,0);
        computeLPS(temp,lps);
        int length=lps[2*n+1-1];

        string res=rev.substr(0,n-length);
        return res+s;
    }
};