class Solution {
public:
    bool check(string &s,int k){
        int ones=0,zero=0;
        for(auto a:s){
            if(a=='0')zero++;
            else ones++;
        }
        return ones<=k or zero<=k;
    }
    int bruteforce(string &s,int k){
        vector<string>temp;
        int n=s.size();
        for(int i=0;i<n;i++){
            string t="";
            for(int j=i;j<n;j++){
                t+=s[j];
                temp.push_back(t);
            }
        }
        int count=0;
        for(auto a:temp){
            if(check(a,k))count++;
        }
        
        return count;
    }
    int countKConstraintSubstrings(string s, int k) {
        // return bruteforce(s,k);

        int n=s.size();
        int res=0,cnt0=0,cnt1=0;
        for(int i=0,j=0;j<n;j++){
            if(s[j]=='0') cnt0++;
            if(s[j]=='1') cnt1++;
            if(cnt0<=k or cnt1<=k){
                res+=(j-i+1);
            }
            else{
                while(i<j and !(cnt0<=k or cnt1<=k)){
                    if(s[i]=='0') cnt0--;
                    if(s[i]=='1') cnt1--;
                    i++;
                }
                if(cnt0<=k or cnt1<=k){
                    res+=(j-i+1);
                }
            }
        }
        return res;
    }
};


























