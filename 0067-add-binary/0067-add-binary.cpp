class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();
        string res="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry=0;
        int i=0,j=0;
        while(i<n and j<m){
            int sum=(a[i]-'0'+b[j]-'0'+carry)%2;
            carry=(a[i]-'0'+b[j]-'0'+carry)/2;
            res+=(sum+'0');
            i++,j++;
        }
        while(i<n ){
            int sum=(a[i]-'0'+carry)%2;
            carry=(a[i]-'0'+carry)/2;
            res+=(sum+'0');
            i++;
        }
        while(j<m){
            int sum=(b[j]-'0'+carry)%2;
            carry=(b[j]-'0'+carry)/2;
            res+=(sum+'0');
            j++;
        }

        if(carry) res+=('1');
        reverse(res.begin(),res.end());
        return res;
    }
};