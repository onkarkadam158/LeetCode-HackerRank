class Solution {
public:
    int solve(string s,int k,char c){
        int n=s.size();
        int count=0,res=0;
        for(int i=0,j=0;i<n and j<n;j++){
            if(s[j]==c) count++;
            if(count<=k){
                res=max(res,j-i+1);
            }
            else{
                while(i<j and count>k){
                    if(s[i]==c) count--;
                    i++;
                }
                if(count<=k){
                    res=max(res,j-i+1);
                }
            }
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,k,'T') ,solve(answerKey,k,'F') );
    }
};