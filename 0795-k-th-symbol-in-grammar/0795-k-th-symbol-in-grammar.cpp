class Solution {
public:
    int bruteforce(int n,int k){
        string str="0";
        for(int i=2;i<=n;i++){
            string temp="";
            for(auto a:str){
                if(a=='1') temp+="10";
                else if (a=='0') temp+="01";
            }
            str=temp;
        }
        return str[k-1]-'0';
    }
    int solve(int n,int k){
        if(n==1) return 0;
        int size=pow(2,n-1);
        if(k<=(size/2)){
            return solve(n-1,k);
        }
        return !solve(n-1,k-size/2);
    }
    int kthGrammar(int n, int k) {
        // return bruteforce(n,k);

        return solve(n,k);
    }
};