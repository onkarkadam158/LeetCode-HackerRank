class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') s[i]='1';
            else if(s[i]=='1') s[i]='0';
        }
        return s;
    }
    string reverseIt(string s){
        reverse(s.begin(),s.end());
        return s;
    }
    char solution1(int n,int k){
        string prev="0";
        for(int i=2;i<=n;i++){
            prev= prev + "1" + reverseIt(invert(prev));
        }
        return prev[k-1];
    }
    char solution2(int n,int k){
        if(n==1) return '0';
        int size=pow(2,n)-1;
        if( k == ( size / 2 + 1) ) return '1';

        if(k < (size/2 + 1) ){
            return solution2(n-1,k);
        }
        char ch=solution2(n-1,size-k+1);
        return ch=='1' ? '0' : '1';
    }
    char findKthBit(int n, int k) {
        // return solution1(n,k);

        return solution2(n,k);
    }
};