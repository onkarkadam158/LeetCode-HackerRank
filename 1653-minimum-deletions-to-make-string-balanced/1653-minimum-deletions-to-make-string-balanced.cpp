class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>pre(n,0),suf(n,0);
        int b=(s[0]=='b');
        int a=(s[n-1]=='a');
        
        for(int i=1;i<n;i++){
            pre[i]=b;
            if(s[i]=='b') b++;

            suf[n-1-i]=a;
            if(s[n-1-i]=='a') a++;
        }
        int res=n;
        for(int i=0;i<n;i++){
            res=min(res,pre[i]+suf[i]);
        }
        return res;
    }
};