class Solution {
public:
    int bruteforce(int num){
        string s=to_string(num);
        int ans=num;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                swap(s[i],s[j]);
                ans=max(ans,int(stoi(s)));
                swap(s[i],s[j]);
            }
        }
        return ans;
    }
    int optimal(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int>maxi(n,-1);
        int maxEle=s[n-1]-'0',maxInd=n-1;
        for(int i=n-1;i>=0;i--){
            maxi[i]=maxInd;    
            if(s[i]-'0'> maxEle){
                maxEle=s[i]-'0';
                maxInd=i;
            }
        }
        for(int i=0;i<n;i++ ){
            cout<<maxi[i]<<" ";
            if(maxi[i]!=i and (s[i]-'0') < (s[maxi[i]] -'0') ){
                swap(s[i],s[maxi[i]]);
                return stoi(s); 
            }
        }
        return num;
    }
    int maximumSwap(int num) {
    //    return bruteforce(num);
        return optimal(num);
    }
};