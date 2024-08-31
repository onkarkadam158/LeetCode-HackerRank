class Solution {
public:
    #define ll long long
    ll getPalAddition(string str,int n){
       
        string res="";
        for(int i=0;i<n/2;i++){
            res+=str[i];
        }
        if(n%2){
            res+=str[n/2];
        }
        ll start=stoll(res);
        start++;
        res=to_string(start);
        
        string end="";
        for(int i=0;i<n/2;i++) end+=res[i];
        reverse(end.begin(),end.end());

        return stoll(res+end);
    }
    ll getPalSub(string str,int n){
        
        string res="";
        for(int i=0;i<n/2;i++){
            res+=str[i];
        }
        if(n%2){
            res+=str[n/2];
        }
        ll start=stoll(res);
        start--;
        res=to_string(start);
        
        string end="";
        for(int i=0;i<n/2;i++) end+=res[i];
        reverse(end.begin(),end.end());

        return stoll(res+end);
    }
    string nearestPalindromic(string str) {
        int n=str.size();
        if(n==1) return to_string(stoll(str)-1);

        vector<ll>palindromes;
        ll temp1=pow(10,n-1)-1, temp2=pow(10,n)+1;

        palindromes.push_back((temp1));
        palindromes.push_back((temp2));

        // without add
        string str1 =str;
        for(int i=0;i<=n/2;i++){
            str1[n-i-1]=str1[i];
        }
        palindromes.push_back(stoll(str1));

        //add one
        palindromes.push_back(getPalAddition(str,n));

        ///sub one
        palindromes.push_back(getPalSub(str,n));



        ll num=stoll(str);
        sort(palindromes.begin(),palindromes.end());
        ll diff = abs(num-palindromes[0]);
        ll res=palindromes[0];
        for(auto a:palindromes){
            cout<<a<<"\n";
            if(a!=num){
                if(abs(a-num) < diff){
                    diff=abs(a-num);
                    res=a;
                }
            }
        }
        return to_string(res);
    }
};