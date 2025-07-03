class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            int n=s.size();
            for(int i=0;i<n;i++){
                char ch=s[i];
                if(ch<'z') ch++;
                else ch='a';
                
                s+=(ch);
            }
        }
        // cout<<s<<" ";
        return s[k-1];
    }
};